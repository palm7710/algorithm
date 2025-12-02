"use strict";

const { expect } = require("chai");
const _ = require("./i18n").text;
const fs = require('fs');
const util = require('util');
const childProcess = require('child_process');
const exec = util.promisify(childProcess.exec);
const performance = require('perf_hooks').performance;

async function commandExec(command) {
  const reslut = await exec(command);
  return reslut.stdout;
}

async function mainOutput(args) {
  const stdout = await commandExec(`node --unhandled-rejections=none js/main.js ${args}`);
  return stdout.trim();
}

function readTxt(path) {
  return fs.readFileSync(path, 'utf8').toString().trim();
}

function selectRunTime(text, info) {
  const regExp = /run time: (.+?)($|\r\n|\r|\n)/;
  const results = text.match(regExp);
  if(results && results[1]) {
    return Number(results[1]);
  }
  expect.fail(_`${info}に予期せぬエラーが検出されました: ${text}`);
}

const expectedNormalStep1_2Text = readTxt("test/out/public/normal/step1_2.txt").trim();
const expectedNormalStep3Text = readTxt("test/out/public/normal/step3.txt").trim();
const expectedNormalStep4ServerText = readTxt("test/out/public/normal/step4_server.txt").split(/\n/);
const expectedNormalStep4CacheText = readTxt("test/out/public/normal/step4_cache.txt").split(/\n/);
const expectedNormalStep5Text = readTxt("test/out/public/normal/step5.txt").split(/\n/);

const expectedErrorStep3Text = readTxt("test/out/public/error/step3.txt").trim();
const expectedErrorPaymentStep5Text = readTxt("test/out/public/error/step5_payment.txt").split(/\n/);
const expectedErrorSubtractInventoryStep5Text = readTxt("test/out/public/error/step5_subtractInventory.txt").split(/\n/);
const expectedErrorAllPaymentStep5Text = readTxt("test/out/public/error/step5_all_payment.txt").split(/\n/);
const expectedErrorAllSubtractInventoryStep5Text = readTxt("test/out/public/error/step5_all_subtractInventory.txt").split(/\n/);

// Step1, Step2
describe(_`[非同期関数の呼出]`, function () {
  it(_`Step1 期待された出力結果が得られる`, async function () {
    const args = "Step1";
    let actual = await mainOutput(args);
    const expected = expectedNormalStep1_2Text;

    expect(actual, _`出力に誤りがあります`).deep.equal(expected);
  });

  it(_`Step2 期待された出力結果が得られる`, async function () {
    const args = "Step2";
    let actual = await mainOutput(args);
    const expected = expectedNormalStep1_2Text;

    expect(actual, _`出力に誤りがあります`).include(expected);
  });
});

// Step3
describe(_`[非同期関数のエラー処理]`, function () {
  it(_`Step3 期待された出力結果が得られる`, async function () {
    let args = "Step3 false";
    let actual = await mainOutput(args);
    let expected = expectedErrorStep3Text;

    expect(actual, _`失敗時の 出力に誤りがあります`).deep.equal(expected);

    // 成功時も含めて1点
    args = "Step3 true";
    actual = await mainOutput(args);
    expected = expectedNormalStep3Text;

    expect(actual, _`成功時の 出力に誤りがあります`).deep.equal(expected);
  });
});

// Step4
describe(_`[複数の非同期処理]`, function () {
  const timeLimit = 4;

  it(_`Step4 期待された時間以内に処理が完了する`, async function () {
    this.timeout(10000 * 3);  // 3回実行分の処理時間
    // serverData が 2秒、cacheData が 3秒のときに期待された時間以内に処理が完了する
    {
      const info = "serverData が 2秒、cacheData が 3秒のとき";

      const args = "Step4 2000 3000";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      const expected = expectedNormalStep4ServerText[1];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }

    // serverData が 0.5秒、cacheData が 4.5秒のときに期待された時間以内に処理が完了する
    {
      const info = "serverData が 0.5秒、cacheData が 4.5秒のとき";

      const args = "Step4 500 4500";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      const expected = expectedNormalStep4ServerText[1];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }

    // serverData が 5秒、cacheData が 1秒のときに期待された時間以内に処理が完了する
    {
      const info = "serverData が 5秒、cacheData が 1秒のとき";

      const args = "Step4 5000 1000";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      const expected = expectedNormalStep4CacheText[1];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }
  });
});

// Step5
describe(_`[複数の非同期処理]`, function () {
  const timeLimit = 4;

  it(_`Step5 期待された時間以内に処理が完了する`, async function () {
    this.timeout(10000 * 4);
    // 非同期処理がすべて成功したときに期待された時間以内に処理が完了する
    {
      const info = "非同期処理がすべて成功したとき";

      const args = "Step5 true true";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      let expected = expectedNormalStep5Text[2];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
      expected = expectedNormalStep5Text[3];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }

    // payment が失敗したときに期待された時間以内に処理が完了する
    {
      const info = "payment が失敗したとき";

      const args = "Step5 false true";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      let expected = expectedErrorPaymentStep5Text[0];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
      expected = expectedErrorPaymentStep5Text[1];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }

    // subtractInventory が失敗したときに期待された時間以内に処理が完了する
    {
      const info = "subtractInventory が失敗したとき";

      const args = "Step5 true false";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      let expected = expectedErrorSubtractInventoryStep5Text[0];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
      expected = expectedErrorSubtractInventoryStep5Text[1];
      expect(actual, _`${info}の出力に誤りがあります`).include(expected);
    }

    // 非同期処理がすべて失敗したときに期待された時間以内に処理が完了する
    {
      const info = "非同期処理がすべて失敗したとき";

      const args = "Step5 false false";
      let actual = await mainOutput(args);

      const runTime = selectRunTime(actual, info);
      expect(runTime, _`${info}の処理時間が制限を超えました`).most(timeLimit);

      actual = actual.split(/\n/);
      let expected = expectedErrorAllPaymentStep5Text[0];

      if(actual.includes(expected)) {
        expected = expectedErrorAllPaymentStep5Text[1];
        expect(actual, _`${info}の出力に誤りがあります`).include(expected);
        return;
      }

      expected = expectedErrorAllSubtractInventoryStep5Text[0];
      if(actual.includes(expected)) {
        expected = expectedErrorAllSubtractInventoryStep5Text[1];
        expect(actual, _`${info}の出力に誤りがあります`).include(expected);
      }
    }
  });
});

"use strict";

const performance = require('perf_hooks').performance;

const replaceStub = require('../js/replaceStub');

const operation = process.argv[2];
execute(operation);

async function stopWatch(func) {
  const start = performance.now();
  try {
    await func();
  } catch (e) {
    console.log(e);
  }
  const end = performance.now();
  let runTime = end - start;
  runTime = (runTime / 1000).toFixed(2);
  return runTime;
}

async function execute(operation) {
  let start;
  let end;
  let runTime;
  switch (operation) {
    case "Step1":
      const { step1 } = require('../js/step1.js');
      await step1();
      break;
    case "Step2":
      const { step2 } = require('../js/step2.js');

      await step2();
      break;
    case "Step3":
      const { step3 } = require('../js/step3.js');
      replaceStub.replaceStubStep3(process.argv)
      try {
        await step3();
      } catch (e) {
        console.log(e);
      }
      break;
    case "Step4":
      const { step4 } = require('../js/step4.js');
      replaceStub.replaceStubStep4(process.argv)
      runTime = await stopWatch(step4);
      console.log(`run time: ${runTime}`);
      break;
    case "Step5":
      const { step5 } = require('../js/step5.js');
      replaceStub.replaceStubStep5(process.argv)
      runTime = await stopWatch(step5);
      console.log(`run time: ${runTime}`);
      break;
    default:
      return;
  }
}

"use strict";

const sinon = require("sinon");
const utils = require('../js/utils');

function replaceStubStep3(argv) {
  let loginUserNameEnabled = true;
  if (process.argv.length >= 4) {
    loginUserNameEnabled = JSON.parse(process.argv[3].toLowerCase());
  }
  if (!loginUserNameEnabled) {
    const stubLoginUserName = sinon.stub(utils, "loginUserName");
    stubLoginUserName.returns(Promise.reject("loginUserName error"));
  }
}

function replaceStubStep4(argv) {
  if (process.argv.length >= 5) {
    const itemData = {"items": [
      {"name": "pen", "price": 1000},
      {"name": "book", "price": 500}
    ]};

    let delayServerData = Number(process.argv[3]);
    let delayCacheData = Number(process.argv[4]);

    const stubServerData = sinon.stub(utils, "serverData");
    stubServerData.callsFake(function () {
      return new Promise(function (resolve) {
        setTimeout(function() {
          console.log("got from server");
          resolve(itemData);
        }, delayServerData);
      });
    });

    const stubCacheData = sinon.stub(utils, "cacheData");
    stubCacheData.callsFake(function () {
      return new Promise(function (resolve) {
        setTimeout(function() {
          console.log("got from cache");
          resolve(itemData);
        }, delayCacheData);
      })
    });
  }
}

function replaceStubStep5(argv) {
  let paymentEnabled = true;
  let subtractInventoryEnabled = true;
  if (process.argv.length >= 5) {
    paymentEnabled = JSON.parse(process.argv[3].toLowerCase());
    subtractInventoryEnabled = JSON.parse(process.argv[4].toLowerCase());
  }
  if (!paymentEnabled) {
    const stubPayment = sinon.stub(utils, "payment");
    stubPayment.returns(Promise.reject("payment error"));
  }
  if (!subtractInventoryEnabled) {
    const stubsubtractInventory = sinon.stub(utils, "subtractInventory");
    stubsubtractInventory.returns(Promise.reject("subtractInventory error"));
  }
}

module.exports = {
  replaceStubStep3,
  replaceStubStep4,
  replaceStubStep5
};

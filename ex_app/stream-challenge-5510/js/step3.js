const utils = require('../js/utils');

async function step3() {
  const name = await utils.loginUserName();
  console.log(`user name: ${name}`);
}

// for main.js
exports.step3 = step3;

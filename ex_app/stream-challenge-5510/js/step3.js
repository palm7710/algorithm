const utils = require("../js/utils");

async function step3() {
  try {
    const name = await utils.loginUserName();
    console.log(`user name: ${name}`);
  } catch (e) {
    console.log("Failed getting: user name");
  }
}

// for main.js
exports.step3 = step3;

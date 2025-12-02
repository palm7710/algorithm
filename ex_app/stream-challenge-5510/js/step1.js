const utils = require("../js/utils");

async function step1() {
  let serverName;
  serverName = await utils.connectingServer();
  console.log(`server name: ${serverName}`);
}

// for main.js
exports.step1 = step1;

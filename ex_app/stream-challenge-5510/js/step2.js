const utils = require('../js/utils');

async function step2() {
  const serverName = utils.connectingServer();
  console.log(`server name: ${serverName}`);
}

// for main.js
exports.step2 = step2;

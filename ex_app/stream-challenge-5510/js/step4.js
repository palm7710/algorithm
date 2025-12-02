const utils = require('../js/utils');

async function step4() {
  let itemData = {};
  itemData = await utils.serverData();
  itemData = await utils.cacheData();
  console.log(`itemData: ${JSON.stringify(itemData)}`);
}

// for main.js
exports.step4 = step4;

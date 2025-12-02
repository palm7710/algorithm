const utils = require('../js/utils');

async function step5() {
  const price = 5500;
  const userId = 2;
  const subtractValue = 3;
  const receiptNo = await utils.payment(userId, price);
  const stock = await utils.subtractInventory(subtractValue);
  console.log("Process completed: purchase");
  console.log(`receiptNo: ${receiptNo} stock: ${stock}`);
}

// for main.js
exports.step5 = step5;

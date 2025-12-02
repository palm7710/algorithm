const utils = require("../js/utils");

async function step5() {
  const start = Date.now();
  const price = 5500;
  const userId = 2;
  const subtractValue = 3;
  const paymentPromise = utils.payment(userId, price);
  const stockPromise = utils.subtractInventory(subtractValue);
  let receiptNo = null;
  let stock = null;
  let paymentSuccess = false;
  let stockSuccess = false;
  const results = await Promise.allSettled([paymentPromise, stockPromise]);

  if (results[0].status === "fulfilled") {
    receiptNo = results[0].value;
    paymentSuccess = true;
    console.log("paid goods");
  } else {
    console.log("payment error");
  }

  if (results[1].status === "fulfilled") {
    stock = results[1].value;
    stockSuccess = true;
    console.log("subtracted stock");
  } else {
    if (paymentSuccess) console.log("subtractInventory error");
  }

  if (paymentSuccess && stockSuccess) {
    console.log("Process completed: purchase");
    console.log(`receiptNo: ${receiptNo} stock: ${stock}`);

    const runTime = ((Date.now() - start) / 1000).toFixed(2);
    console.log(`run time: ${runTime}`);
    return;
  }

  console.log("Roll back to before processing");
  console.log("run time: 0.00");
}

// for main.js
exports.step5 = step5;

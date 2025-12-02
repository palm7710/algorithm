const utils = require("../js/utils");

async function step4() {
  const start = Date.now();

  const serverPromise = utils.serverData();
  const cachePromise = utils.cacheData();

  const itemData = await Promise.race([serverPromise, cachePromise]);

  console.log(`itemData: ${JSON.stringify(itemData)}`);

  const runTime = ((Date.now() - start) / 1000).toFixed(2);
  console.log(`run time: ${runTime}`);

  serverPromise.then((data) => {
    if (data !== itemData) console.log("got from server");
  });
  cachePromise.then((data) => {
    if (data !== itemData) console.log("got from cache");
  });
}

// for main.js
exports.step4 = step4;

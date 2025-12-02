"use strict";

// 接続中のサーバ名を取得する
function connectingServer() {
  const serverName = "sv1";
  return new Promise(function(resolve) {
    setTimeout(function() {
      resolve(serverName);
    }, 500);
  });
}

// ログインしているユーザ名を返す
function loginUserName() {
  const name = "alice";
  return new Promise(function(resolve) {
    setTimeout(function() {
      resolve(name);
    }, 600);
  });
}

// サーバからデータを取得する
function serverData() {
  const itemData = {"items": [
    {"name": "pen", "price": 1000},
    {"name": "book", "price": 500}
  ]};
  return new Promise(function(resolve) {
    setTimeout(function() {
      console.log("got from server");
      resolve(itemData);
    }, 2000);
  });
}

// キャッシュからデータを取得する
function cacheData() {
  const itemData = {"items": [
    {"name": "pen", "price": 1000},
    {"name": "book", "price": 500}
  ]};
  return new Promise(function(resolve) {
    setTimeout(function() {
      console.log("got from cache");
      resolve(itemData);
    }, 3000);
  });
}

// 決済処理をする
function payment(userId, price) {
  const receiptNo = "1023";
  return new Promise(function(resolve) {
    setTimeout(function() {
      console.log("paid goods");
      resolve(1023);
    }, 3000);
  });
}

// 在庫を更新する
function subtractInventory(subtractValue) {
  let stock = 99;
  stock -= subtractValue;
  return new Promise(function(resolve) {
    setTimeout(function() {
      console.log("subtracted stock")
      resolve(stock);
    }, 2000);
  });
}

module.exports = {
  connectingServer,
  loginUserName,
  serverData,
  cacheData,
  payment,
  subtractInventory
};

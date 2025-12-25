## async 　と　 await の意味と関係は？

```
async は「この関数は非同期で、戻り値は必ず Promise にな
る」という宣言です。
await は「Promise の完了を待って、その結果を取り出す」
ためのキーワードで、async 関数の中でしか使えません。
関係としては、async が土台、await がその中で使う待機・取り
出し手段です。
```

## Promise になるとは？

```
その値が「今すぐ結果が出るとは限らない処理」を表す
Promiseオブジェクトになる、という意味
Promise は「成功したらこの値」「失敗したらこのエラー」
という“将来の結果”を表します。
だから async 関数は「将来の結果」を返すので、
戻り値は必ずPromise になります。
```

## try と catch の関係を教えてください

```
try は「エラーが起きるかもしれない処理」を実行するブロック、
catch は「try の中で起きた例外を受け取って処理する」ブロックです。
関係としては、try の中で例外が発生すると処理が中断され、
対応する catch に移ってエラー対応を行います。
```

## 「サーバー取得とキャッシュ取得を同時に開始して、早く返ってきた方を採用し、後からもう一方の結果も確認する」処理の説明

```
- start で開始時刻を記録。
- utils.serverData() と utils.cacheData() を同時に行（Promiseを作る）。
- Promise.race でどちらか早く解決した方の結果を itemDataにする。
- itemData を出力。
- 経過時間を計算して出力。
- その後、サーバー/キャッシュそれぞれの結果が itemData と違った場合に「どちらから来たか」をログに出す。

レスポンスが速い方をすぐ使いつつ、遅れて返る方の
情報も把握するためのコード
```

## 「支払い処理」と「在庫減算処理」を同時に実行し、両方成功したら購入完了、どちらか失敗したらロールバック扱いにする処理

```
- utils.payment(userId, price) と utils.subtractInventory(subtractValue) を同時に開始。
- Promise.allSettled で「成功/失敗を両方とも」結果として受け取る。
- 支払いが成功したら領収書番号を保存して「paid goods」を出力、失敗なら「payment error」。
- 在庫減算が成功したら在庫値を保存して「subtracted stock」を出力、失敗でかつ支払いだけ成功していたら「subtractInventory error」。
- 両方成功なら「Process completed: purchase」を出して、領収書番号と在庫、実行時間を表示して終了。
- 片方でも失敗なら「Roll back to before processing」を出して処理終了（実際のロールバック処理は書かれていないログのみ）。
```

## 1. await Promise.allSettled([paymentPromise, stockPromise]);

```
- paymentPromise と stockPromise はそれぞれ非同期処理（支払い・在庫減算）の Promise です。
- Promise.allSettled([...]) は「両方の Promise が 成功しても失敗しても 終了するまで待つ」関数です。
- どちらかが失敗しても例外で止まらず、必ず配列で結果が返るのが特徴です。
- 返ってくる results は配列で、各要素が次の形になります。
- 成功した場合: { status: "fulfilled", value: 成功時の値 }
- 失敗した場合: { status: "rejected", reason: エラー内容 }
- つまりこの行は「支払いと在庫減算の両方が終わるまで待って、成功/失敗の結果を配列で受け取る」という意味です。
```

## 2. ((Date.now() - start) / 1000).toFixed(2);

```
- Date.now() は「今の時刻（ミリ秒）」を返します。
- start は処理開始時に Date.now() で記録していた値です。
- Date.now() - start で「経過時間（ミリ秒）」が出ます。
- / 1000 でミリ秒を秒に変換します。
- .toFixed(2) は小数点以下 2 桁に丸めた文字列にします。
- つまりこの行は「処理にかかった秒数を小数点 2 桁で文字列として保存する」という意味です。
```

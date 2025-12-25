## 「ホテル予約 API を使って、指定プランが検索結果にあるか確認し、条件に応じて予約する」処理

```
- 引数から token と jsonStr（予約条件のJSON文字列）を受け取る。なければ missing arguments。
- jsonStr を JSON.parse し、失敗したら invalid json。
- ホテル検索APIに keyword / checkin / checkout / number を付けてGETし、結果を取得。
- 検索結果の中に params.plan_id のプランが存在するかを確認。
- 見つかった場合は予約APIにPOSTし、成功したら予約ID（resData.id）を出力して終了。
- 見つからない場合は plan not found を出し、それでも予約APIにPOSTしてエラー内容を判定。
- 404なら plan_id does not exist
- 409なら full reservations
- それ以外なら plan_id exists. You should change search keyword.

最後に main(process.argv.slice(2)) でCLI引数から実行
```

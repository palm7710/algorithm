-- カテゴリ別に本の数を知りたいです boolsテーブルを集計し、 カテゴリ別の本の数の一覧を出力する
SELECT c.name AS category_name, 
  COUNT(*) AS count
FROM books AS b
JOIN categories AS c 
  ON b.category_id = c.id
GROUP BY c.name;  

-- SELECT AS: 取得する列や計算結果に別名を付ける
-- COUNT(*) AS: 行数を数え、その結果に別名を付ける
-- JOIN AS ON: テーブルを結合し、ON で結合条件を指定する
-- GROUP BY: 指定した列ごとに行をグループ化する
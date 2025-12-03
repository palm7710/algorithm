-- カテゴリ別に本の数を知りたいです boolsテーブルを集計し、 カテゴリ別の本の数の一覧を出力する
SELECT c.name AS category_name, 
  COUNT(*) AS count
FROM books AS b
JOIN categories AS c 
  ON b.category_id = c.id
GROUP BY c.name;  
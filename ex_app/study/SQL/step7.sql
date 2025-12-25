-- 一定ページ数以上の本を別の棚に移動する booksテーブルで pagesが953ページ以上の本のタイトルとカテゴリ名の一覧を求めるSQL
SELECT b.title, c.name AS category_name
FROM books AS b
JOIN categories AS c
  ON b.category_id = c.id
WHERE b.pages >= 953;

-- SELECT AS: 取得する列に別名（エイリアス）を付ける
-- FROM AS: 参照するテーブルに別名を付ける
-- JOIN AS ON: 別名付きのテーブル同士を結合し、ON で結合条件
--              を指定する
-- WHERE: 条件で行を絞り込む

-- books と categories をカテゴリIDで結合し、
-- ページ数が953以上の本だけを対象に、
-- 本のタイトルとカテゴリ名
-- （category_name という別名）を取得するSQLです。
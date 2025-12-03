-- 一定ページ数以上の本を別の棚に移動する booksテーブルで pagesが953ページ以上の本のタイトルとカテゴリ名の一覧を求めるSQL
SELECT b.title, c.name AS category_name
FROM books AS b
JOIN categories AS c
  ON b.category_id = c.id
WHERE b.pages >= 953;
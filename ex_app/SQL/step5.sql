-- 新着の本の一覧を取得したい booksテーブルで 本の発行年月日published_at が新しい順に 本の一覧を１０件まとめて出力する
SELECT id, title, published_at
FROM books
ORDER BY published_at DESC
LIMIT 10;
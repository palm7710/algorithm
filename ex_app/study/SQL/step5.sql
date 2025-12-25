-- 新着の本の一覧を取得したい booksテーブルで 本の発行年月日published_at が新しい順に 本の一覧を１０件まとめて出力する
SELECT id, title, published_at
FROM books
ORDER BY published_at DESC
LIMIT 10;

-- SELECT: 取得したい列（項目）を指定する
-- FROM: どのテーブル（やビュー）から取得するかを指定する
-- ORDER BY DESC: 指定した列で降順（大きい→小さい、新しい→古
--                いなど）に並べ替える
-- LIMIT: 取得する件数の上限を指定する
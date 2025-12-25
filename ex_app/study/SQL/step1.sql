-- カテゴリID が5である本をbooksテーブルから全て出力する
SELECT title
FROM books
WHERE category_id = 5
ORDER BY title;

-- SELECT: 取得したい列（項目）を指定する
-- FROM: どのテーブル（やビュー）から取得するかを指定する
-- WHERE: 条件を指定して、行を絞り込む
-- ORDER BY: 並び順を指定して、結果をソートする
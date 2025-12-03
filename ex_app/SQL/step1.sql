-- カテゴリID が5である本をbooksテーブルから全て出力する
SELECT title
FROM books
WHERE category_id = 5
ORDER BY title;
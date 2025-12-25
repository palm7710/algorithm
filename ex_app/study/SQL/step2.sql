-- categoriesテーブルにカテゴリ名がActionのレコードを追加する、単一のSQLクエリ カテゴリIDは指定しない 自動採番を使用する
INSERT INTO categories (name)
VALUES ('Action');

-- INSERT INTO: どのテーブルに新しい行を追加するかを指定する
-- (name) は、値を入れる「列名」の指定。
-- VALUES: 追加する具体的な値（各列に入れるデータ）を指定する
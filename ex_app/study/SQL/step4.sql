-- 特定の名前を含むユーザーを検索したい userテーブルを参照し ユーザー名にpaulを含むユーザーの情報を全て取得して出力するSQL
SELECT id, name
FROM users
WHERE name LIKE '%paul%';

-- SELECT: 取得したい列（項目）を指定する
-- FROM: どのテーブル（やビュー）から取得するかを指定する
-- WHERE: 条件を指定して、行を絞り込む
-- name LIKE: name 列が指定したパターンに一致する行だけを選
--                 ぶ（% は任意の文字列、_ は任意の1文字）
-- 特定の名前を含むユーザーを検索したい userテーブルを参照し ユーザー名にpaulを含むユーザーの情報を全て取得して出力するSQL
SELECT id, name
FROM users
WHERE name LIKE '%paul%';
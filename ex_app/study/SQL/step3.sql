-- あるユーザーのメールアドレスを変更したい userテーブルでIDが2であるユーザーについて メールアドレスをjohn.sample@demo.netに変更する
UPDATE users
SET email = 'john.sample@demo.net'
WHERE id = 2;

-- UPDATE: 既存の行を更新する対象テーブルを指定する
-- SET: 変更する列と新しい値を指定する
-- WHERE: 更新対象の行を条件で絞り込む
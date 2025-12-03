-- あるユーザーのメールアドレスを変更したい userテーブルでIDが2であるユーザーについて メールアドレスをjohn.sample@demo.netに変更する
UPDATE users
SET email = 'john.sample@demo.net'
WHERE id = 2;
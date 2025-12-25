-- 古い貸し出し情報を削除 rentalsテーブルで rent_end_timeが2023_01_31 23:59:59 以前である貸し出し情報を削除する
DELETE FROM rentals
WHERE rent_end_time <= '2023-01-31 23:59:59';

-- DELETE FROM: 指定したテーブルの行を削除する
-- WHERE: 削除対象の行を条件で絞り込む
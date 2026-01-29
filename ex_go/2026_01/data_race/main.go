package main

/*
	データの競合　：単一のデータに対して同時に読み書きを行うことで、データの一貫が取れなくなる現象のこと
	期待する出力としては、[2 4 6 8 10](順不同)ですが
	期待通りの結果にならないどころか、実行ごとに結果が違う
*/

import (
	"fmt"
	"time"
)

func main() {
	src := []int{1, 2, 3, 4, 5}
	dst := []int{}

	//　src の要素ごとにある何か処理をして、結果を dst に入れる
	for _, s := range src {
		go func(s int) {
			// 何か（重い）処理をする
			result := s * 2

			// 結果を　dst に入れる
			dst = append(dst, result)
		}(s)
	}

	time.Sleep(time.Second)
	fmt.Println(dst)
}

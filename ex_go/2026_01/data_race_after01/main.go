package main

/*
	ゴールーチン間で値をやり取りする場合には、チャネルを使うのが一番安全
*/

import (
	"fmt"
)

func main() {
	src := []int{1, 2, 3, 4, 5}
	dst := []int{}

	c := make(chan int)

	//　src の要素ごとにある何か処理をして、結果を dst に入れる
	for _, s := range src {
		go func(s int, c chan int) {
			// 何か（重い）処理をする
			result := s * 2

			c <- result;
		}(s, c)
	}

	for _ = range src {
		num := <-c
		// 結果を　dst に入れる
		dst = append(dst, num)
	}

	fmt.Println(dst)
	close(c)
}


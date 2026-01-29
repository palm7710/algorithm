package main

import "fmt"

/*
	「エラトステネスのふるい」のアルゴリズム
	1：go mod init example.com/prime_sieve
	2：go run
*/

// 2, 3, 4, 5...と自然数を送信するチャネルを作る
func generate(ch chan<- int) {
	for i := 2; ; i++ {
		ch <- i
	}
}

// src チャネルから送られてくる値の中で、prime の倍数でない値だけを dst チャネルに送信する関数
// src: 受信専用チャネル（入力）
// dst: 送信専用チャネル（出力）
// prime: 除外に使う素数
func filter(src <-chan int, dst chan<- int, prime int) {
	for i:= range src {
		// prime の倍数を弾く
		if i%prime != 0 {
			dst <- i
		}
	}
}

// エストステネスのふるいのアルゴリズム本体
func sieve() {
	ch := make(chan int)
	go generate(ch)
	for {
		prime := <- ch // ここから受け取るものは素数で確定
		fmt.Print(prime, "\n")

		// 素数と確定した数字の倍数は
		// もう送ってこないようにチャネルを新規作成->chに代入
		ch1 := make(chan int)
		go filter(ch, ch1, prime)
		ch = ch1
	}
}

func main() {
	sieve()
}

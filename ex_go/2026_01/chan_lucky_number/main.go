package main

import (
	"fmt"
	"math/rand"
	"time"
)

/*
	「今日のラッキーナンバーを占って表示する」ゴールーチン
	チャネルを使った値の送受信
	チャネルは「異なるゴールーチン同士が、特定の型の値を送受信することでやりとりする機構」である
	1：go mod init example.com/main
	2：go run .
*/

// 今日のラッキーナンバーを占って表示する関数
func getLuckyNum(c chan<- int) {
	fmt.Println("...")

	// 占いにかかる時間はランダム
	rand.Seed(time.Now().Unix())
	time.Sleep(time.Duration(rand.Intn(3000)) * time.Millisecond)

	num := rand.Intn(10)
	// メインゴールーチンにラッキーナンバー num をどうにかして伝える
	c <- num
}

func main() {
	fmt.Println("what is today's lucky number?")

	c := make(chan int)
	go getLuckyNum(c)

	// ゴールーチンで起動した getLuckyNum 関数から
	// ラッキーナンバーを変数 num に取得してくる
	num := <-c

	fmt.Printf("Today's your lucky number is %d!\n", num)

	// 使い終わったチャネルは close する
	close(c)
}

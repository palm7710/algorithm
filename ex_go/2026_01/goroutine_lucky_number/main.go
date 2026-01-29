package main

import (
	"fmt"
	"math/rand"
	"sync"
	"time"
)

/*
	「今日のラッキーナンバーを占って表示する」ゴールーチン
	「同期をとる」という作業をここで実現
	1：go mod init example.com/main
	2：go run .
*/

// 今日のラッキーナンバーを占って表示する関数
func getLuckyNum() {
	fmt.Println("...")

	// 占いにかかる時間はランダム
	rand.Seed(time.Now().Unix())
	time.Sleep(time.Duration(rand.Intn(3000)) * time.Millisecond)

	num := rand.Intn(10)
	fmt.Printf("Today's your lucky number is %d!\n", num)
}

func main() {
	fmt.Println("what is today's lucky number?")
	
	// sync.WaitGroup：別のゴールーチンが終わるのを待っていたい場合に使う構造体
	// 内部にカウンタを持っており、初期化時点でカウンタの値は0
	var wg sync.WaitGroup
	wg.Add(1) // 内部カウンタの値を+1する

	go func() {
		defer wg.Done() // ゴールーチンが終了したときにwgの内部カウンタの値を-1する
		getLuckyNum()
	}()

	wg.Wait() // wgの内部カウンタが0になるまでメインゴールーチンをブロックして待つ
}

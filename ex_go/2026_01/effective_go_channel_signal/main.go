package main

import (
	"fmt"
	"sort"
	"time"
)

// ソートアルゴリズムが終わるまで終わるまで別のことをする関数
func doSomethingForAWhile() {
	time.Sleep(300 * time.Millisecond)
	fmt.Println("作業中...")
}

func main() {
	list := []int{5, 2, 4, 3, 1}

	c := make(chan int) // チャネルを確保する。
	// goroutine で sort を開始し、完了したらチャネルに通知する。
	go func() {
		sort.Ints(list)
		c <- 1 // 完了通知を送る。値自体は何でもよい。
	}()

	doSomethingForAWhile()
	<-c // ソートが終わるまで待機。受け取った値は捨てる。

	fmt.Println("sorted:", list)
}

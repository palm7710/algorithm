package main

/*
	チャネルというのは送受信だけではなくて実行同期のための機構でもある
*/

import (
	"fmt"
	"sort"
	"time"
)

type List []int

func (l List) Sort() {
	sort.Ints(l)
}

func main() {
	list := List{5, 3, 4, 1, 2}
	c := make(chan int)

	// 別ゴールーチンでソートを実行し、終わったらチャネルで通知する
	go func() {
		list.Sort()
		c <- 1 // 送信する値自体は意味を持たない
	}()

	doSomethingForAWhile()

	<-c // ソート完了の通知を待つ（値は捨てる）
	fmt.Println(list)
}

func doSomethingForAWhile() {
	// 何か別の処理をしている想定
	time.Sleep(100 * time.Millisecond)
}

def main():
    # 入力
    N, K = map(int, input().split())
    A = [0] + list(map(int, input().split()))  # インデックス1から始まるように調整

    # 全探索 (sum は書かれた整数の合計 / Answer は現時点での答え)
    Answer = False
    for i in range(1 << N):
        sum = 0
        for j in range(1, N + 1):
            if (i >> (j - 1)) & 1:
                sum += A[j]
        if sum == K:
            Answer = True

    # 出力
    if Answer:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

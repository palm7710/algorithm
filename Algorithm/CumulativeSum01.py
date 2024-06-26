def main():
    # 入力
    N, Q = map(int, input().split())
    A = [0] + list(map(int, input().split()))  # インデックス1から始まるように調整
    L = [0] * (Q + 1)
    R = [0] * (Q + 1)
    for j in range(1, Q + 1):
        L[j], R[j] = map(int, input().split())

    # 累積和の計算
    S = [0] * (N + 1)
    for i in range(1, N + 1):
        S[i] = S[i - 1] + A[i]

    # 質問に答える
    for j in range(1, Q + 1):
        print(S[R[j]] - S[L[j] - 1])

if __name__ == "__main__":
    main()

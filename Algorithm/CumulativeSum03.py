def main():
    # 入力
    H, W = map(int, input().split())
    X = [[0] * (W + 1) for _ in range(H + 1)]
    for i in range(1, H + 1):
        X[i][1:] = map(int, input().split())

    Q = int(input())
    A = [0] * (Q + 1)
    B = [0] * (Q + 1)
    C = [0] * (Q + 1)
    D = [0] * (Q + 1)
    for i in range(1, Q + 1):
        A[i], B[i], C[i], D[i] = map(int, input().split())

    # 横方向に累積和を取る
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            Z[i][j] = Z[i][j - 1] + X[i][j]

    # 縦方向に累積和を取る
    for j in range(1, W + 1):
        for i in range(1, H + 1):
            Z[i][j] += Z[i - 1][j]

    # 答えを求める
    results = []
    for i in range(1, Q + 1):
        result = Z[C[i]][D[i]]+ Z[A[i]-1][B[i]-1] - Z[A[i]-1][D[i]] - Z[C[i]][B[i]-1]
        results.append(result)

    # 出力
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
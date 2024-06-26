def main():
    # 入力
    H, W, N = map(int, input().split())
    A = [0] * (N + 1)
    B = [0] * (N + 1)
    C = [0] * (N + 1)
    D = [0] * (N + 1)
    for t in range(1, N + 1):
        A[t], B[t], C[t], D[t] = map(int, input().split())

    # 配列の初期化
    X = [[0] * (W + 2) for _ in range(H + 2)]
    Z = [[0] * (W + 2) for _ in range(H + 2)]

    # 各日について加算
    for t in range(1, N + 1):
        X[A[t]][B[t]] += 1
        X[A[t]][D[t] + 1] -= 1
        X[C[t] + 1][B[t]] -= 1
        X[C[t] + 1][D[t] + 1] += 1

    # 二次元累積和をとる
    for i in range(1, W + 1):
        for i in range(1, H + 1):
            Z[i][j] += Z[1 - 1][j]

    #出力
    for i in range(1, H + 1):
        for j in range(1, W + 1):
            if j > 1:
                print(" ", end="")
            print(Z[i][j], end="")
        print()

if __name__ == "__main__":
    main() 
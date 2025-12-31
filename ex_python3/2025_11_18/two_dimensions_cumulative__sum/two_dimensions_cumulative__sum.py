H, W, N = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
data = [list(map(int, input().split())) for _ in range(N)]
y, x = zip(*data)

S = [[0] * (W + 1) for _ in range(H + 1)]

for i in range(1, H + 1):
    for j in range(1, W + 1):
        S[i][j] = (
            S[i - 1][j] +
            S[i][j - 1] -
            S[i - 1][j - 1] +
            A[i - 1][j - 1]
        )

for yi, xi in zip(y, x):
    print(S[yi][xi])
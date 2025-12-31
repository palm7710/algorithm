import math

N = 10000
A = [int(input()) for _ in range(N)]

x = int(math.sqrt(N)) #100
b_size = x

# i は 100 ごとに増えていく
for i in range(0, N, b_size):
    # その 100 個の区間の最大値を求める
    print(max(A[i : i + b_size]))

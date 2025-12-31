N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
data = [list(map(int, input().split())) for _ in range(K)]
l, r = zip(*data)

S = [0] * (N + 1)

for i in range(1, N + 1):
   S[i] = S[i - 1] + A[i - 1]

for li, ri in zip(l, r):
    print(S[ri] - S[li - 1])


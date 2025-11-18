N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]
Q = [int(input()) for _ in range(K)]

ans = [0] * (N + 1)
for i in range(1, N+1):
    ans[i] = ans[i - 1] + A[i - 1]

for qi in Q:
    print(ans[qi])

N, Q = map(int, input().split())
A = {int(input()) for _ in range(N)} #setで受け取る
K = [int(input()) for _ in range(Q)]

for i in range(Q):
    if K[i] in A:
        print("YES")
    else:
        print("NO")
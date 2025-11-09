N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]

if K in A:
    print("YES")
else:
    print("NO")

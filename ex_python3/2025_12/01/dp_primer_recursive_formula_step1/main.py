x, d = map(int, input().split())
Q = int(input())

for _ in range(Q):
    k = int(input())
    print(x + d * (k - 1))

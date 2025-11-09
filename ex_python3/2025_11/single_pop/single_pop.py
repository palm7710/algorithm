N = int(input())
A = [int(input()) for _ in range(N)]

A.pop(0)

for x in A:
    print(x)
N, X, P = map(int, input().split())
A = [int(input()) for _ in range(N)]

A.append(X)
A.append(P)

A.sort()

if P in A:
    print(A.index(P) + 1)
N, K, P = map(int, input().split())
A = [int(input()) for _ in range(N)]

A.append(P)

for _ in range(K):
    event = input().split()

    if event[0] == "join":
        A.append(int(event[1]))
    elif event[0] == "sorting":
        A.sort()
        if P in A:
            print(A.index(P) + 1)


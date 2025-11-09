N, K = map(int, input().split())
A = [int(input()) for _ in range(N)]

for _ in range(K):
    S = input()

    if (S == "pop"):
        A.pop(0)
    elif (S == "show"):
        for x in A:
            print(x)

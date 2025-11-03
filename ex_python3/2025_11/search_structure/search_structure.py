N = int(input())
data = [list(input().split()) for _ in range(N)]
n, o, b, s = zip(*data)
K = int(input())

for i in range(N):
    if (int(o[i]) == K):
        print(n[i])
        break



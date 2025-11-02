N, K = list(map(int, input().split()))
data = [list(input().split()) for _ in range(N)]
n, o, b, s = zip(*data)
updates = [input().split() for _ in range(K)]

n, o, b, s = list(n), list(o), list(b), list(s)

for update in updates:
    a, nn = int(update[0]), update[1]
    n[a-1] = nn

for i in range(N):
    print(f"{n[i]} {o[i]} {b[i]} {s[i]}")
N, K = map(int, input().split())
data = [input().split() for _ in range(N)]

bank = {c: (int(p), int(d)) for c, p, d in data}

for _ in range(K):
    event = input().split()

    if event[0] in bank:
        p, d = bank[event[0]]
        if int(event[1]) == p:
            d -= int(event[2])
            bank[event[0]] = (p, d)

for x in bank:
    p, d = bank[x]
    print(f"{x} {d}")
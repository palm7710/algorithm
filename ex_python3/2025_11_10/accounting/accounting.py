N, K = map(int, input().split())
S = [input() for _ in range(N)]

kaikei = {name: [] for name in S}

for _ in range(K):
    data = input().split()
    name = data[0]
    values = (data[1], int(data[2]))

    if name in kaikei:
        kaikei[name].append(values)

for x in kaikei:
    print(x)
    for p, d in kaikei[x]:
        print(p, d)
    print("-----")
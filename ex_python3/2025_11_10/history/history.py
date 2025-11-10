N, K = map(int, input().split())
S = [input() for _ in range(N)]
data = {}

for _ in range(K):
    num, name = input().split()
    num = int(num)
    if num not in data:
        data[num] = []
    data[num].append(name)

for key in sorted(data.keys()):
    for name in data[key]:
        print(name)


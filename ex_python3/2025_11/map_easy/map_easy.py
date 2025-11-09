N, K = map(int, input().split())
data = dict(input().split() for _ in range(N))

for _ in range(K):
    query = input().strip()
    if query in data:
        print(data[query])
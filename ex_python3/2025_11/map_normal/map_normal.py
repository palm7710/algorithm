N, K = map(int, input().split())
data = dict(input().split() for _ in range(N))

for _ in range(K):
    S  = input().split()
    
    if S[0] == "join":
        key = S[1]
        value = S[2]
        data[key] = value
    elif S[0] == "leave":
        key = S[1]
        if key in data:
            data.pop(key)
    elif S[0] == "call":
        key = S[1]
        if key in data:
            print(data[key])

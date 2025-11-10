N, K = map(int, input().split())
name = set(input().strip() for _ in range(N))

for _ in range(K):
    S = input().split()
    cmd = S[0]

    if S[0] == "join":
        name.add(S[1])
    elif S[0] == "leave":
        name.discard(S[1])
    elif S[0] == "handshake":
        for n in sorted(name):
            print(n)
N = int(input())
data = [input().split() for _ in range(N)]
n, o, b, s = zip(*data)

for i in range(N):
    print("User{")
    print(f"nickname : {n[i]}")
    print(f"old : {o[i]}")
    print(f"birth : {b[i]}")
    print(f"state : {s[i]}")
    print("}")
N, K, S = map(int, input().split())

a = [""] * (N + 1)
r1 = [0] * (N + 1)
r2 = [0] * (N + 1)

for i in range(1, N+1):
    line = input().split()
    a[i] = line[0]
    r1[i] = int(line[1])
    r2[i] = int(line[2])

M = [int(input()) for _ in range(K)]

pos = S
spell = a[pos]

for m in M:
    if m == 1:
        pos = r1[pos]
    else:
        pos = r2[pos]
    spell += a[pos]

print(spell)
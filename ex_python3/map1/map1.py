H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
x, y = map(int, input().split())

S[x][y] = "#"

for row in S:
    print(''.join(row))
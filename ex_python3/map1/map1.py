H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
y, x = map(int, input().split())

S[y][x] = '#' if S[y][x] == '.' else '.'

for row in S:
    print(''.join(row))
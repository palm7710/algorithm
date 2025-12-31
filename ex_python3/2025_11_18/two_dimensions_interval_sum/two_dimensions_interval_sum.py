import sys
input = sys.stdin.readline

H, W, N = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(H)]

S = [[0] * (W + 1) for _ in range(H + 1)]

for i in range(1, H + 1):
    row = A[i - 1]
    for j in range(1, W + 1):
        S[i][j] = row[j-1] + S[i-1][j] + S[i][j-1] - S[i-1][j-1]

def rect(y1, x1, y2, x2):
    return (
        S[y2][x2]
        - S[y1-1][x2]
        - S[y2][x1-1]
        + S[y1-1][x1-1]
    )

out_lines = []
for _ in range(N):
    a, b, c, d = map(int, input().split())
    ans = rect(a, b, c, d)
    out_lines.append(str(ans))

print("\n".join(out_lines))

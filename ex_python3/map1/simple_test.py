H, W = map(int, input().split())
print(f"H={H}, W={W}")

S = [list(input()) for _ in range(H)]
print("マップ:")
for i, row in enumerate(S):
    print(f"{i}: {row}")

x, y = map(int, input().split())
print(f"座標: x={x}, y={y}")
print(f"変更前 S[{x-1}][{y-1}] = '{S[x-1][y-1]}'")

S[x-1][y-1] = "#"
print(f"変更後 S[{x-1}][{y-1}] = '{S[x-1][y-1]}'")

print("結果:")
for row in S:
    print(''.join(row))
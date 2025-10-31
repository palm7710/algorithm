H, W = map(int, input().split())
print(f"H={H}, W={W}")

S = [list(input()) for _ in range(H)]
print("読み込んだマップ:")
for i, row in enumerate(S):
    print(f"行{i}: {row} (長さ: {len(row)})")

x, y = map(int, input().split())
print(f"座標: x={x}, y={y}")

# 座標を0-indexedに変換
S[x-1][y-1] = "#"
print(f"変更後の座標 [{x-1}][{y-1}] = '#'")

print("最終結果:")
for row in S:
    print(''.join(row))
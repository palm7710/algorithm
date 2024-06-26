#全探索01
# 入力
N = int(input())
X = int(input())
A = list(map(int, input().split()))

# 全探索 (変数 Answer は「既に X が見つかったかどうか」を表す)
Answer = False
for i in range(N):
    if A[i] == X:
        Answer = True

# 出力
if Answer:
    print("Yes")
else:
    print("No")

n = int(input())
a = list(map(int, input().split()))
k = int(input())

cnt = 0
for i in range(n):
    if a[i] == k:
        cnt += 1

print(cnt)
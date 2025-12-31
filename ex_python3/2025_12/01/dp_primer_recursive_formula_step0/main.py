x, d, k = map(int, input().split())

a = [0] * (k + 1)
a[1] = x

for i in range(2, k+1):
    a[i] = a[i - 1] + d

print(a[k])
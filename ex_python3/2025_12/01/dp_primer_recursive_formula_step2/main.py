x, d1, d2, k = map(int, input().split())

if k == 1:
    print(x)
elif k % 2 == 1:
    t = (k - 1) // 2
    print(x + t * d1 + t * d2)
else:
    t = k // 2
    print(x + (t - 1) * d1 + t * d2)

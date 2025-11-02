N = int(input())
data = [input().split() for _ in range(N)]

data.sort(key=lambda x: x[1])

for row in data:
    print(f"{row[0]} {row[1]} {row[2]} {row[3]}")


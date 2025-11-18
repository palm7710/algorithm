N = int(input())

member = {}

for _ in range(N):
    data = input().split()
    name = data[0]

    if name not in member:
        member[name] = {"give": 0, "ship": False}

    if data[1] == "give":
        member[name]["give"] += int(data[2])
    elif data[1] == "join":
        member[name]["ship"] = True

for name, info in sorted(
    member.items(),
    key=lambda x: (x[1]["give"], x[0]), 
    reverse=True
):
    if info['ship'] == False:
        print(f"{name}")

for name in sorted(
    [n for n, i in member.items() if i["ship"]]
):
    print(f"{name}")

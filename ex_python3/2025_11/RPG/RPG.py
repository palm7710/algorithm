N, K = map(int, input().split())

heros = []
for _ in range(N):
    l, h, a, d, s, c, f = map(int, input().split())
    heros.append({
        "l": l,
        "h": h,
        "a": a,
        "d": d,
        "s": s,
        "c": c,
        "f": f,
    })

for i in range(K):
    event = input().split()
    n = int(event[0]) - 1

    cmd = event[1]

    if (cmd == "levelup"):
        vals = list(map(int, event[2:9]))
        keys =  ["h", "a", "d", "s", "c", "f"]
        for k, v in zip(keys, vals):
            heros[n][k] += v
        heros[n]["l"] += 1
    elif (cmd == "muscle_training"):
        heros[n]["h"] += int(event[2])
        heros[n]["a"] += int(event[3])
    elif (cmd == "running"):
        heros[n]["d"] += int(event[2])
        heros[n]["s"] += int(event[3])
    elif (cmd == "study"):
        heros[n]["c"] += int(event[2])
    elif (cmd == "pray"):
        heros[n]["f"] += int(event[2])
    
for i in range(N):
    hero = heros[i]
    print(hero["l"], hero["h"], hero["a"], hero["d"], hero["s"], hero["c"], hero["f"])

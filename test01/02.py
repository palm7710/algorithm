def next_mayor():
    results = []
    
    while True:
        # 標準入力から候補者の人数 n と初期の小石の数 p を読み取ります。
        try:
            line = input().strip()
        except EOFError:
            break
        
        if not line:
            continue
        
        n, p = map(int, line.split())
        if n == 0 and p == 0:
            break
        
        candidates = [0] * n
        current_p = p
        current_candidate = 0
        
        while True:
            if current_p > 0:
                candidates[current_candidate] += 1
                current_p -= 1
            else:
                current_p = candidates[current_candidate]
                candidates[current_candidate] = 0
            
            if current_p == 0 and all(x == 0 for x in candidates):
                break
            
            current_candidate = (current_candidate + 1) % n
        
        results.append(current_candidate)
    
    for result in results:
        print(result)

# プログラムを実行します。
next_mayor()

def main():
    # 入力
    N, K = map(int, input().split())
    Answer = 0
    
    # 全探索
    for x in range(1, N + 1):
        for y in range(1, N + 1):
            for z in range(1, N + 1):
                if x + y + z == K:
                    Answer += 1
    
    # 出力
    print(Answer)

if __name__ == "__main__":
    main()

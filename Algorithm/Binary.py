def main():
    # 入力
    N = int(input())
    
    # 上の桁から順番に「2進法に変換した値」を求める
    result = []
    for x in range(9, -1, -1):
        wari = (1 << x)  # 2のx乗
        result.append((N // wari) % 2)  # 割り算の結果に応じて0または1を追加
    
    # 結果を出力
    print(''.join(map(str, result)))

if __name__ == "__main__":
    main()

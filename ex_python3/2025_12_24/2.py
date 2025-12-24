def solution(cards, moves, query):
    # TODO: Implement me!
    # cards: [カードID, 行インデックス, 列インデックス]
    # moves: [カードID, 移動前の行インデックス, 移動前の列インデックス, 移動先の行インデックス, 移動先の列インデックス]
    # query: 直接動かす対象となるカードのID
    # ans: queryで指定されたカードの最終的な位置を [行のインデックス, 列のインデックス]

    row, col = None, None
    for i, r, c in cards:
        if i == query:
            row, col = r, c
            break
    
    for i in moves:
        c_id, r, c, fr, fc = i
        if c_id == query:
            row, col = fr, fc
    
    return [row, col]
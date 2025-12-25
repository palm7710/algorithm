def solution(intervals):
    # TODO: Implement me!
    # intervals の各要素は [start, end]
    # intervals = [[1,3], [2,4], [5,7]]
    # intervals[0] と intervals[1] を組み合わせることで、 [1,4] という間隔を作ることができる
    # 結果として [[1,4], [5,7]]
    intervals.sort(key=lambda x: x[0])

    i_list = []
    n_start, n_end = intervals[0]

    for start, end in intervals[1:]:
        if start <= n_end:
            if end <= n_end:
                n_end = n_end
            else:
                n_end = end
        else:
            i_list.append([n_start, n_end])
            n_start, n_end = start, end
    
    i_list.append([n_start, n_end])
    return i_list

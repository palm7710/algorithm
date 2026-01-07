#!/bin/python3

import math
import os
import random
import re
import sys

def getSubstringCount(s):
    # まずsを左から見て、同じ文字が連続する長さを数える
    runs = []
    cnt = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            cnt += 1
        else:
            runs.append(cnt)
            cnt = 1
    runs.append(cnt)

    # (runs[i], runs[i+1]) ごとに、 min(runs[i], runs[i+1]) 個
    ans = 0
    for i in range(len(runs) - 1):
        ans += min(runs[i], runs[i + 1])
    
    return ans


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = getSubstringCount(s)

    fptr.write(str(result) + '\n')

    fptr.close()

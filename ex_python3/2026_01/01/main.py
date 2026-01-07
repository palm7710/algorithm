#!/bin/python3

import math
import os
import random
import re
import sys

def getString(input_str):
    # Write your code here
    last = {}
    for i, ch in enumerate(input_str):
        last[ch] = i

    stack = []
    in_stack = set()

    for i, ch in enumerate(input_str):
        if ch in in_stack:
            continue

        while stack and stack[-1] < ch and last[stack[-1]] > i:
            in_stack.remove(stack.pop())

        stack.append(ch)
        in_stack.add(ch)

    return "".join(stack)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    input_str = input()

    result = getString(input_str)

    fptr.write(result + '\n')

    fptr.close()

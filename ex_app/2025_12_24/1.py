def solution(s):
    stack = []
    kakko = {
        "(":")",
        "{":"}",
        "[":"]"
    }
    # TODO: Implement me!
    for i in s:
        if i in kakko:
            stack.append(i)
        else:
            if not stack:
                return False
            k = stack.pop()
            if kakko[k] != i:
                return False

    return len(stack) == 0

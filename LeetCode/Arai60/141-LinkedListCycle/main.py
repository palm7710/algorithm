# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        pos = head.val

        # head に　pos 番目の数字があるか
        while head and head.next:
            pos = head.next
            head = head.next
            if pos == head:
                return True
        return False
        
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dest = set()
        pos = head

        while pos:
            if pos in dest:
                return pos
            dest.add(pos)
            pos = pos.next

        return None

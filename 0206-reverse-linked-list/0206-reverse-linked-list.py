# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head):
        if head is None:
            return None

        p = head
        r = head.next
        q = None

        while r is not None:
            p.next = q

            q = p
            p = r
            r = r.next

        p.next = q
        return p
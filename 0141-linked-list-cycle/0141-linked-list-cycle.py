# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head==None:
            return False
        curr = head
        visited = set()
        while curr is not None:
            if id(curr.next) in visited:
                return True
            
            visited.add(id(curr))
            curr = curr.next
        
        return False
        
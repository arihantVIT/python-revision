# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None or head.next is None:
            return head
        my_list=[]
        temp = head
        while temp:
            my_list.append(temp.val)
            if temp.next:
                temp = temp.next.next
            else:
                temp=None
        temp = head.next
        while temp:
            my_list.append(temp.val)
            if temp.next:
                temp = temp.next.next
            else:
                temp=None
        
        idx=0
        temp=head
        while temp:
            temp.val = my_list[idx]
            idx+=1
            temp=temp.next
        
        return head
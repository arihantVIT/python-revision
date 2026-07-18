class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        temp = head

        while temp:
            length += 1
            temp = temp.next

        pos = length - n

        # Remove the head
        if pos == 0:
            return head.next

        temp = head
        for _ in range(pos - 1):
            temp = temp.next

        temp.next = temp.next.next

        return head
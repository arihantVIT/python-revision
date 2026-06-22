class Solution:
    def middleNode(self, head):
        count = 0
        temp = head

        while temp is not None:
            count += 1
            temp = temp.next

        curr = head

        for _ in range(count // 2):
            curr = curr.next

        return curr
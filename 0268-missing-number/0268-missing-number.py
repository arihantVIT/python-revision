class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums_sorted=sorted(nums)
        nums_all=[]
        n=len(nums)
        for i in range(0,n+1):
            nums_all.append(i)
        for i in range(len(nums_all)):
            if i not in nums_sorted:
                return i
        
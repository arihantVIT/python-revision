class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count=0
        count_list=[]
        for i in range(len(nums)):
            if nums[i]==1:
                count+=1
            else:
                count_list.append(count)
                count=0
        count_list.append(count)
        return max(count_list)
class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        num_pos=[]
        num_negative=[]
        n=len(nums)
        for num in nums:
            if num>=0:
                num_pos.append(num)
            
            else:
                num_negative.append(num)
        
        for i in range(n//2):
            nums[2*i] = num_pos[i]
            nums[2*i + 1] = num_negative[i]
        
        return nums
        
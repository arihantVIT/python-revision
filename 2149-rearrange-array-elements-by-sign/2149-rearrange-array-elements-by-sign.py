class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
            l = len(nums)
            result = [0]*l

            p=0
            n=1

            for i in range(l):
                if nums[i]>=0:
                    result[p] = nums[i]
                    p+=2
                elif nums[i]<0:
                    result[n] = nums[i]
                    n+=2
            
            nums[:] = result[:]

            return nums
        
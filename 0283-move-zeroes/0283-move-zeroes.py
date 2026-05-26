class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
            temp = []

            # store non-zero elements
            for num in nums:
                if num != 0:
                    temp.append(num)

            # put non-zero elements back
            for i in range(len(temp)):
                nums[i] = temp[i]

            # fill remaining positions with zeros
            for i in range(len(temp), len(nums)):
                nums[i] = 0
        
        
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        l = 0
        h = n-1

        ans = n
        while l<=h :
            mid = (l+h)//2
            if nums[mid]>=target:
                ans = mid
                h = mid-1
            else:
                l = mid+1
        
        return ans

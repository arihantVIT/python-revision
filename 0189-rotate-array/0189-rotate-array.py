class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        r = k%n

        nums[:] = nums[n-r:] + nums[:n-r]
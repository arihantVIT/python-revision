class Solution:
    def search(self, nums: List[int], target: int) -> int:
        hash_map = {}
        n = len(nums)

        for i in range(n):
            hash_map[nums[i]] = i
        
        nums.sort()
        l = 0
        h = n-1
        while l<=h :
            mid = (l+h)//2

            if nums[mid]==target:
                return hash_map[nums[mid]]
            elif nums[mid] > target:
                h = mid-1
            else:
                l = mid+1
        
        return -1
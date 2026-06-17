class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def first_occur():
            n = len(nums)
            l, h = 0, n-1
            ans = -1

            while l<=h :
                mid = (l+h)//2

                if nums[mid] == target:
                    ans = mid
                    h = mid-1
                elif nums[mid]<target:
                    l = mid+1
                else:
                    h = mid-1
            
            return ans

        def last_occur():
            n = len(nums)
            l, h = 0, n-1
            ans = -1

            while l<=h :
                mid = (l+h)//2

                if nums[mid] == target:
                    ans = mid
                    l = mid + 1
                elif nums[mid]<target:
                    l = mid+1
                else:
                    h = mid-1
            
            return ans
        
        return [first_occur(), last_occur()]

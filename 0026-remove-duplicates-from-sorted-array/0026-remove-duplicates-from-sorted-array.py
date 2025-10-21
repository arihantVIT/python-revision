class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        empty_set = set()
        unique_nums = []
        for num in nums:
            if num not in empty_set:
                unique_nums.append(num)
                empty_set.add(num)
        nums[:len(unique_nums)] = unique_nums
        return len(unique_nums)
        
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        freqMap={}
        n = len(nums)
        keys=[]

        for num in nums:
            if num in freqMap:
                freqMap[num]+=1
            else:
                freqMap[num] = 1
        
        for key in freqMap:
            keys.append(key)

        for j in range(len(keys)):
            nums[j] = keys[j]

        return len(keys)        
        
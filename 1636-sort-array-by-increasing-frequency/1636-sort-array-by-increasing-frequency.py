class Solution:
    def get_frequency_map(self):
        numList = self.nums
        freq_map = dict()
        for i in range(0,len(numList)):
            if numList[i] in freq_map:
                freq_map[numList[i]] += 1
            else:
                freq_map[numList[i]] = 1
        return freq_map
    def frequencySort(self,nums):
        self.nums = nums
        freq_map = self.get_frequency_map()
        result = sorted(nums, key= lambda x: (freq_map[x], -x))
        
        return result
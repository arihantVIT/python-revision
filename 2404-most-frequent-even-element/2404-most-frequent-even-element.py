class Solution:
    def getFreqMap(self):
        l = self.nums
        freq_map=dict()

        for num in l:
            if num in freq_map:
                freq_map[num] += 1
            else:
                freq_map[num] = 1
        
        return freq_map
    def mostFrequentEven(self, nums):
        self.nums = nums

        freq_map = self.getFreqMap()
        evenNums=[]
        even_freq = dict()
        for num in freq_map:
            if num%2==0:
                even_freq[num] = freq_map[num]
                evenNums.append(num)
        if even_freq == {}:
            return -1
        result = sorted(evenNums, key= lambda x: (even_freq[x], -x))
        return result[-1]

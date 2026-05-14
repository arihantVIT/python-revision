class Solution(object):
    def getFreq(self):
        s = self.word
        freq_map = dict()
        for char in s:
            if char in freq_map:
                freq_map[char]+=1
            else:
                freq_map[char] = 1
        return freq_map
    def equalFrequency(self, word):
        self.word = word
        freq_map = self.getFreq()

        for char in freq_map:
            freq_map[char] -= 1

            freq_list = []

            for key in freq_map:
                if freq_map[key]>0:
                    freq_list.append(freq_map[key])
            
            if len(set(freq_list)) == 1:
                return True
            
            freq_map[char] += 1
        return False
        
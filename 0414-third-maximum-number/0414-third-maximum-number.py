class Solution(object):


    def thirdMax(self, nums):
        num = list(set(nums))
        n = len(num)

        #insertion sort
        for i in range(1,n):
            if num[i] < num[i-1]:
                key = num[i]
                j = i-1
                while j>=0 and num[j]>key:
                    num[j+1] = num[j]
                    j-=1
                num[j+1] = key
        
        if n<3:
            return num[-1]
        
        return num[-3]
        
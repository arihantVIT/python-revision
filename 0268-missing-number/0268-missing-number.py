class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        myDict={}

        for i in range(0,n+1):
            myDict[i] = 0
    
        #updating dictionary
        for num in nums:
            if num in myDict:
                myDict[num]+=1
    
        for key in myDict:
            if myDict[key]==0:
                return key
    
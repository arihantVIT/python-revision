
class Solution(object):
    def digit_counter(self,x):
        n = x
        count=0
        while n>0 :
            count+=1
            n = n//10
        
        
        return count
    def extractDigits(self,x):
        n = x
        digits=[]
        while n>0 :
            digit = n%10
            digits.append(digit)
            n = n//10
        
        return digits
    def isPalindrome(self, x):
        if x<0 :
            return False
        if x>=0 and x<=9 :
            return True
        n = x
        length = self.digit_counter(n)
        rDigits = self.extractDigits(n)
        sum=0
        j=length-1
        for i in range(0,length):
            sum+= rDigits[i]*(10**j)
            j-=1
        
        return sum==n
        

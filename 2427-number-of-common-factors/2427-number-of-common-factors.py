from math import sqrt

class Solution:
    def getFactors(self, num):
        n = num
        factors=[]
        for i in range(1,int(sqrt(n))+1):
            if n%i == 0:
                factors.append(i)

                if (n/i != i) :
                    factors.append(int(n/i))
        factors.sort()
        return factors
    def commonFactors(self, a, b):
        n1 = a
        n2 = b
        a_facs = self.getFactors(n1)
        b_facs = self.getFactors(n2)
        i = 0
        j = 0
        count=0
        while(i<len(a_facs) and j<len(b_facs)):
            if a_facs[i] == b_facs[j]:
                count+=1
                i+=1
                j+=1
            elif a_facs[i] > b_facs[j]:
                j+=1
            else:
                i += 1

        return count
            




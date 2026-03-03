def karatsuba(x,y):
    if int(x)<10 or int(y)<10:
        return int(x)*int(y)
    else:
        n = max(len(str(x)), len(str(y)))
        half = n//2
        a = int(x)//(10**(half))
        b = int(x)%(10**(half))
        c = int(y)//(10**(half))
        d = int(y)%(10**(half))
        ac = karatsuba(a,c)
        bd = karatsuba(b,d)
        ad_plus_bc = karatsuba(a+b,c+d) - ac - bd
        return ac*(10**(2*half)) + (ad_plus_bc*(10**half)) + bd

class Solution(object):
    def multiply(self, num1, num2):
        return(str(karatsuba(num1,num2)))
        
        
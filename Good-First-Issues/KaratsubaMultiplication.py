import math
#to use log2() function

mod=10**9+7
def karatsuba(a,b):
    if len(a)==1:
        return int(a)*int(b)
    #base case

    n=len(a)
    a1=a[:n//2]
    a2=a[n//2:]
    #splitting the string into two halfs
    #a=a1*10^(n/2)+a2

    b1=b[:n//2]
    b2=b[n//2:]
    #splitting the string into two halfs
    #b=b1*10^(n/2)+b2

    #multiplying a*b in expanded form, recursively
    return (karatsuba(a1,b1)*(10**n) + (karatsuba(a2,b1)+karatsuba(b2,a1))*(10**(n//2)) + (karatsuba(a2,b2)))%mod

def convertToGood(a,b):

    lenA=2**(int(math.log2(len(a))) +1) #calculating the nearest power of 2 >= len(A)
    lenB=2**(int(math.log2(len(b))) +1) #calculating the nearest power of 2 >= len(B)

    a="0"*(max(lenA,lenB)-len(a))+a
    b="0"*(max(lenA,lenB)-len(b))+b
    #converting both a and b to string of same length of some (2^n) 
    return (a,b)

#to convert the numbers to be input in the karastuba function into an acceptable form,i.e,length should be in power of 2.

str1,str2=map(str,input().split())

str1=str(int(str1,2))
str2=str(int(str2,2))
#string input of binary-->integer equivalent-->string form

s=convertToGood(str1,str2)
print(karatsuba(s[0],s[1]))
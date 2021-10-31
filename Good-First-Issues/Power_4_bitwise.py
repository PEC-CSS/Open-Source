# function for check power of 4 by Using bit manipulation.
# N=integer input
# leetcode-342
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        
        if num < 0:
            return False

        s = bin(num).replace("0b", "")
        # number power of 4 has total odd number of bits with only '1' bit

        if s.count("1") == 1:
            if len(s) % 2 == 1:
                return True
            else:
                return False
        else:
            return False

# Auther: Prashant kumar

# function for check power of 4 by Using bit manipulation.
# N=integer input
def hacktoberfest(N):
    if (N == 0):
        return False
    while (N != 1):
            if (N % 4 != 0):
                return False
            N = N // 4
             
    return True

# Auther: Prashant kumar

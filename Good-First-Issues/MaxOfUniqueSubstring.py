class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        global value_holder  #declared a global variable 
        value_holder = 0 #initialized the same to 0
        check = defaultdict(int) 
        def rec(index,s,ans):
            global value_holder
            if(index>=len(s)):
                value_holder = max(value_holder,ans)
            for i in range(index+1,len(s)+1):
                if(check[s[index:i]] == 0):
                    check[s[index:i]] = 1
                    rec(i,s,ans+1)
                    check[s[index:i]] = 0
        rec(0,s,0)
        return value_holder
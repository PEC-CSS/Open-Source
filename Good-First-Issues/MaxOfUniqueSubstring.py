class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        global cnt
        cnt = 0
        check = defaultdict(int)
        def rec(index,s,ans):
            global cnt
            if(index>=len(s)):
                cnt = max(cnt,ans)
            for i in range(index+1,len(s)+1):
                if(check[s[index:i]] == 0):
                    check[s[index:i]] = 1
                    rec(i,s,ans+1)
                    check[s[index:i]] = 0
        rec(0,s,0)
        return cnt
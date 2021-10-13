class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        
        
        def backTracking(curr_path, s):
            if not s:
                return len(curr_path)
            
            res = 0
            for i in range(1, len(s) + 1):
                sub_string = s[0 : i]
                if sub_string not in curr_path:
                    res = max(res, backTracking(curr_path + [sub_string], s[i : ]))
                    
            return res
        
        L = backTracking([], s)
        return L

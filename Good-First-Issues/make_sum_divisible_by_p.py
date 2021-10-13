class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        for i in range(len(nums)):
            nums[i]%=p
        toFind = sum(nums)%p
        d = {}
        d[0]=-1
        cur = 0
        m = float('inf')
        if toFind==0:
            return 0
        for i in range(len(nums)):
            cur+=nums[i]
            cur%=p
            
            if (cur-toFind)%p in d:
                m = min(m,i-d[(cur-toFind)%p])
            d[cur]=i
        if m==float('inf') or m==len(nums):
            return -1
        return m
            

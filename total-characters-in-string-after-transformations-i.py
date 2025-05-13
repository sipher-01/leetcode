class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = 10**9+7
        mp = [0]*26
        for ch in s:
            mp[ord(ch)-ord("a")] += 1
        
        for round in range(t):
            nxt = [0]*26
            nxt[0] = mp[25]
            nxt[1] = mp[25] + mp[0]
            for i in range(2,26):
                nxt[i] = mp[i-1]
            mp = nxt
        
        ans = sum(mp)%mod
        return ans
        
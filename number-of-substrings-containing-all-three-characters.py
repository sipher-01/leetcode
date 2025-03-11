class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        dict = {}
        r = 0
        l = 0
        n = len(s)
        ans = 0
        while r<n:
            dict[s[r]] = dict.get(s[r],0)+1
            while len(dict)>=3:
                ans += n-r
                dict[s[l]] = dict.get(s[l],0)-1
                if(dict.get(s[l])==0):
                    dict.pop(s[l])
                l+=1
            r+=1
        return ans
        
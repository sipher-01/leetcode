class Solution:
    def h_dist(self,str1,str2):
        n = len(str1)
        cnt = 0
        for i in range(n):
            if str1[i] != str2[i]:
                cnt += 1
        
        return cnt
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(groups)
        dp = [1]*n
        parent = [-1]*n
        ls = 0
        lsi = 0

        for i in range(n):
            for j in range(0,i):
                if groups[i]!=groups[j] and len(words[i])==len(words[j]) and self.h_dist(words[i],words[j])==1:
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        parent[i] = j
                        if ls < dp[i]:
                            ls = dp[i]
                            lsi = i
        
        ans = []
        while lsi!=-1:
            ans.append(words[lsi])
            lsi = parent[lsi]
        
        ans.reverse()
        return ans


        
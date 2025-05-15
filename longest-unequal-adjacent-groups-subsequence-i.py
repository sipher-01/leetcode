class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        prev = groups[0]
        ans = []
        ans.append(words[0])
        for i in range(1,len(groups)):
            if prev == groups[i]:
                continue
            else:
                prev = groups[i]
                ans.append(words[i])
        
        return ans
        
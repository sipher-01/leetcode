from collections import defaultdict
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        mp = defaultdict(int)
        len = 0
        central = False
        for num in words:
            mp[num] += 1
        for word in list(mp.keys()):
            rev = word[::-1]
            if word == rev:
                pairs = mp[word]//2
                len += pairs*4
                if mp[word]%2==1:
                    central = True
                del mp[word]
            elif word<rev:
                if rev in mp:
                    pairs = min(mp[word], mp[rev])
                    len += pairs * 4  # Each pair contributes 4 characters
                    
                    # Remove both from dictionary
                    del mp[word]
                    del mp[rev]
        
        if central:
            len += 2
        return len
        

        
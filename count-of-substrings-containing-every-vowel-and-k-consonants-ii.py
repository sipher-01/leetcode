from collections import defaultdict
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        return self.atleast(word,k) - self.atleast(word,k+1)
    
    def atleast(self,word,k)->int:
        substr = 0
        s = 0
        e = 0
        n = len(word)
        vowel_count = defaultdict(int)
        consonant = 0
        while e<n:
            c = word[e]
            if(self.is_vowel(c)):
                vowel_count[c] += 1
            else:
                consonant+=1
            
            while len(vowel_count)==5 and consonant>=k:
                substr += n-e
                sc = word[s]
                if self.is_vowel(sc):
                    vowel_count[sc] -= 1
                    if vowel_count[sc]==0: del vowel_count[sc]
                else:
                    consonant -= 1
                s+=1

            e+=1
        return substr
    
    def is_vowel(self,c)->bool:
        return c in {'a','e','o','i','u'}

        
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        count = defaultdict(int)
        for a, b in dominoes:
            key = tuple(sorted((a, b)))  # ensures (1,2) and (2,1) are treated the same
            count[key] += 1
        
        ans = 0
        for val in count.values():
            ans += val * (val - 1) // 2
        
        return ans



        
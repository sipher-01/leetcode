class Solution:
    def check(self,x,n,tops,bottoms):
        top_r = bottom_r = 0
        for i in range(0,n):
            if(x!=tops[i] and x!=bottoms[i]):
                return float('inf')
            elif (x!=tops[i]):
                top_r+=1
            elif (x!=bottoms[i]):
                bottom_r+=1
        
        return min(top_r,bottom_r)
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        cand1 = self.check(tops[0],len(tops),tops,bottoms)
        cand2 = self.check(bottoms[0],len(tops),tops,bottoms)
        ans = min(cand1,cand2)
        return ans if ans!=float('inf') else -1
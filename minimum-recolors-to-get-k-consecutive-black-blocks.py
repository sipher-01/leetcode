class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        l = 0
        n = len(blocks)
        cnt = 0
        ans = 101
        for r in range(n):
            if blocks[r]=='W': cnt+=1
            if r-l+1>k:
                if blocks[l]=='W':
                    cnt-=1
                l+=1
            if r-l+1==k:
                ans = min(ans,cnt)
        return ans

        
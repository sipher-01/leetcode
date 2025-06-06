class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        uf = ascii_lowercase
        for i,j in sorted({tuple(sorted(map(ord,p))) for p in zip(s1,s2)}):
            # small elements go first, root of each union - smallest element
            uf = uf.replace(*sorted((uf[i-97],uf[j-97]))[::-1]) # union operation

        return ''.join(uf[ord(c)-97] for c in baseStr)
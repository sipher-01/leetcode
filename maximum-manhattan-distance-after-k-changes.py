class Solution:
    def maxDistance(self, s: str, k: int) -> int:
        latitude = 0
        longitude = 0
        ans = 0
        n = len(s)
        for i in range(n):
            if s[i] == "N":
                latitude += 1
            elif s[i] == "S":
                latitude -= 1
            elif s[i] == "E":
                longitude += 1
            elif s[i] == "W":
                longitude -= 1
            mhd = abs(latitude) + abs(longitude)
            steps = i+1
            waste = steps - mhd
            extra = 0
            if waste!=0:
                extra = min(2*k,waste)
            final = mhd + extra
            ans = max(ans, final)
        return ans

        
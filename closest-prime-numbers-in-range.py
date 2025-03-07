class Solution:
    def erotosthenes(self,right):
        is_prime = [True]*(right+1)
        is_prime[0] = is_prime[1] = False

        for i in range(2,int(math.sqrt(right))+1):
            if is_prime[i]:
                for multi in range(i*i,right+1,i):
                    is_prime[multi] = False
        
        return is_prime

    def closestPrimes(self, left: int, right: int) -> List[int]:
        ans = [-1,-1]
        prime = self.erotosthenes(right)
        sieve = []
        for i in range(left,right+1):
            if prime[i]:
                sieve.append(i)
        n = len(sieve)
        if n<2: return ans
        mini = 1000001
        for i in range(n-1,0,-1):
            if (sieve[i]-sieve[i-1])<=mini:
                mini = sieve[i]-sieve[i-1]
                ans[0] = sieve[i-1]
                ans[1] = sieve[i]
        
        return ans


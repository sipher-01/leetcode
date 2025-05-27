class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        sum = (n*(n+1))//2
        last = (n-m)//m + 1
        sum2=(2*last*m + last*(last-1)*m)//2
        return sum - 2*sum2
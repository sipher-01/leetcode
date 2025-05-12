class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        x = digits
        carry = 0
        for i in range(len(digits)-1,-1,-1):
            if x[i] + 1!=10:
                x[i] += 1
                return x
            x[i] = 0
            if i==0:
                return [1] + x

            
        
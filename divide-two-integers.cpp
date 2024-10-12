class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if(divisor==0)return INT_MAX;
        long long  m = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while(m>=d){
             long long temp = d, multiple = 1;
            while (m >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            m -= temp;
            ans += multiple;
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);
        ans = isNegative ? -ans : ans;

        // Ensure the result fits in the 32-bit signed integer range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;
        return ans;
    }
};
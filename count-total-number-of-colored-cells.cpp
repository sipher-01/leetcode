class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        n--;
        long long fact = 4;
        while(n--){
            ans +=fact;
            fact += 4;
        }
        return ans;
    }
};
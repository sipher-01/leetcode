class Solution {
    #define mod 1000000007
    vector<int>dp;
public:
    int solve(int s, int len, int zero, int one, int low){
        if (s > len) return 0;
        if(dp[s]!=-1)return dp[s];
        int sum = 0;
        if(s>=low)sum+=1;
        sum = (sum + solve(s + zero, len, zero, one, low))%mod;
        sum = (sum + solve(s + one,len,zero,one, low))%mod;

        return dp[s] = sum % mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        dp = vector<int>(100001,-1);
        return solve(0,high,zero,one,low); 
        
    }
};
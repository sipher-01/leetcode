class Solution {
    // vector<vector<int>>dp;
    int dp[201][201][2];
public:
    const int mod = 1e9 + 7;
    int solve(int zleft, int oleft, bool is_one, int limit){
        if(zleft==0 && oleft==0){
            return 1;
        }
        if(dp[zleft][oleft][is_one]!=-1)return dp[zleft][oleft][is_one];
        int ans = 0;
        if(is_one){
            for(int i=1; i<=min(zleft,limit); i++){
                ans = (ans + solve(zleft-i,oleft,false,limit))%mod;
            }
        }
        else{
            for(int i=1; i<=min(limit,oleft); i++){
                ans = (ans + solve(zleft,oleft - i, true, limit))%mod;
            }
        }
        return dp[zleft][oleft][is_one] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        int start_one = solve(zero,one,true,limit);
        int start_zero = solve(zero, one, false, limit);
        // dp = vector<vector<int>>(zero+one+1,vector<int>(2,-1));
        return (start_one + start_zero)%mod;
    }
};
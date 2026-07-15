class Solution {
    int n;
    const int mod = 1e9+7;
    int dp[201][201][201];
public:

    int GCD(int a, int b){
        if(b>a){
            return GCD(b,a);
        }
        if(b==0)return a;
        return GCD(b,a%b);
    }
    int solve(int i, int gcd1, int gcd2, vector<int>&nums){
        if(i==n){
            if((gcd1!=0 && gcd2!=0 )&& (gcd1 == gcd2)){
                return 1;
            }
            return 0;
        }
        if(dp[i][gcd1][gcd2]!=-1)return dp[i][gcd1][gcd2];
        int ans = 0;
        //skip
        ans = (ans + solve(i+1,gcd1,gcd2,nums))%mod;

        //add seq1
        int new_gcd1 = GCD(gcd1,nums[i]);
        ans = (ans + solve(i+1,new_gcd1,gcd2,nums))%mod;

        //add seq2
        int new_gcd2 = GCD(gcd2,nums[i]);
        ans = (ans + solve(i+1,gcd1,new_gcd2,nums))%mod;

        return dp[i][gcd1][gcd2] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0,0,nums);
        return ans;
    }
};
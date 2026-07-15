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
        // int ans = solve(0,0,0,nums);
        // return ans;
        int mx = *max_element(nums.begin(),nums.end());
        // int dp[n+1][mx+1][mx+1] = {0};
        std::vector<std::vector<std::vector<int>>> dp(n + 1, 
            std::vector<std::vector<int>>(mx + 1, std::vector<int>(mx + 1, 0)));
        // memset(dp,0,sizeof(dp));
        // base case
        for(int i=1; i<=mx; i++){
            // for(int j=1; j<mx)
            dp[n][i][i] = 1;
        }

        for(int i=n-1; i>=0; i--){
            for(int first = mx; first>=0; first--){
                for(int second=mx; second>=0; second--){
                    //skip
                    dp[i][first][second] = (dp[i][first][second] + dp[i+1][first][second])%mod;

                    //add seq1
                    int new_first = GCD(first,nums[i]);
                    dp[i][first][second] = (dp[i][first][second] + dp[i+1][new_first][second])%mod;

                    //add seq2
                    int new_second = GCD(second,nums[i]);
                    dp[i][first][second] = (dp[i][first][second] + dp[i+1][first][new_second])%mod;

                }
            }
        }
        return dp[0][0][0];

    }
};
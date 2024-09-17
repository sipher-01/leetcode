class Solution {
public:
    int solve(int ind, int target, vector<int>& coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(target%coins[ind]==0)return target / coins[ind];
            return 1e9;
        }
        if(dp[ind][target]!= -1)return dp[ind][target];
        int np = 0 + solve(ind-1,target,coins,dp);
        int p = INT_MAX;
        if(coins[ind]<=target)p = 1 + solve(ind,target-coins[ind],coins,dp);
        return dp[ind][target] = min(p,np);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // int ans = solve(n-1,amount,coins,dp);
        // if(ans == 1e9)return -1;
        // return ans;
        for(int i=0; i<=amount; i++){
            if(i%coins[0] == 0)dp[0][i] = i/coins[0];
            else dp[0][i] = 1e9;
        }
        for(int i = 1; i<n ; i++){
            for(int j = 0 ;j<=amount ; j++){
                int np = 0 + dp[i-1][j];
                int p = 1e9;
                if(coins[i]<=j)p = 1 + dp[i][j-coins[i]] ;
                dp[i][j] = min(p,np);
            }
        }

        if(dp[n-1][amount]>=1e9)return -1;
        return dp[n-1][amount];

    }
};
class Solution {
public:
    int solve(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size()) return 0;  // Base case: If index exceeds the size, return 0
        if (dp[ind][buy] != -1) return dp[ind][buy];  // Return if already computed
        
        if (buy) {
            // Two choices: Buy or skip buying
            return dp[ind][buy] = max(solve(ind + 1, 0, prices, dp) - prices[ind], solve(ind + 1, 1, prices, dp));
        } else {
            // Two choices: Sell or skip selling (with cooldown of 1 day after selling)
            return dp[ind][buy] = max(solve(ind + 2, 1, prices, dp) + prices[ind], solve(ind + 1, 0, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); 
        // return solve(0,1,prices,dp);
        for(int ind=n-1; ind>=0; ind--){
            for(int buy =0; buy<=1; buy++){
                if (buy) {
                    dp[ind][buy] = max(dp[ind + 1][0]- prices[ind],
                    dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(dp[ind + 2][1] + prices[ind],
                    dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
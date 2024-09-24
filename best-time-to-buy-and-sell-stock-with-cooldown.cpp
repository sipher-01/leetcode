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
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return solve(0,1,prices,dp);
    }
};
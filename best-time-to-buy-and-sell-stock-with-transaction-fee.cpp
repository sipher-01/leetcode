class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
                int n = prices.size();
        // vector<vector<int>> dp(n+2, vector<int>(2, 0)); 
        // return solve(0,1,prices,dp);
        vector<int>ahead(2,0),cur(2,0);
        for(int ind=n-1; ind>=0; ind--){
            for(int buy =0; buy<=1; buy++){
                if (buy) {
                    cur[buy] = max(ahead[0]- prices[ind],ahead[1]);
                } else {
                    cur[buy] = max(ahead[1] + prices[ind]-fee,ahead[0]);
                }
            }
            ahead = cur;
        }
        return ahead[1];
    }
};
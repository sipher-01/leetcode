class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>ahead(2,vector<int>(k+1,0));
        vector<vector<int>>cur(2,vector<int>(k+1,0));
        // return solve(0,1,2,prices,dp);
        // dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = 0;
        // dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 0;
        // for(int i=0; i<=n; i++){
        //     dp[i][0][0] = 0;
        //     dp[i][1][0] = 0;
        // }
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<2; buy++){
                for(int cap=1; cap<=k; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(ahead[0][cap]-prices[ind],
                            ahead[1][cap]);
                    }
                    else{
                        profit = max(ahead[1][cap-1]+prices[ind],
                            ahead[0][cap]);
                    }
                    cur[buy][cap] = profit;
                }
            }
            ahead = cur;
        }
        return ahead[1][k];
    }
};
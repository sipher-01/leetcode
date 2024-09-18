class Solution {
public:
        int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i=0; i<=amount; i++){
            if(i%coins[0] == 0)prev[i] = 1;
            else prev[i] = 0;
        }
        for(int i = 1; i<n ; i++){
            for(int j = 0 ;j<=amount ; j++){
                int np =  prev[j];
                int p = 0;
                if(coins[i]<=j)p =  curr[j-coins[i]] ;
                curr[j] = p+np;
            }
            prev = curr;
        }

        return prev[amount];

    }
    int change(int amount, vector<int>& coins) {
        return coinChange(coins,amount);
    }
};
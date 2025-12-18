using ll = long long;
class Solution {
public:
    ll dp[1001][501][3];
    ll f(int i, vector<int>& prices, int k, int c){
        if(i>=prices.size()){
            if(c==0)return 0;
            return INT_MIN;
        }
        if(dp[i][k][c]!=INT_MIN)return dp[i][k][c];
        ll notTake = f(i+1,prices,k,c);
        ll take = INT_MIN;
        if(k>0){
            if(c==1){
                take = f(i+1,prices,k-1,0) + prices[i];
            }
            else if(c==2){
                take = f(i+1,prices,k-1,0) - prices[i];
            }
            else{
                take = max(f(i+1,prices,k,1) - prices[i], f(i+1, prices,k,2) + prices[i]);
            }
        }
    return dp[i][k][c] = max(take,notTake);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                for(int k=0; k<3; k++){
                    dp[i][j][k] = INT_MIN;
                }
            }
        }
        return f(0,prices,k,0);
    }
};
class Solution {
public:
    using ll = long long;
    ll solve(int i, vector<vector<int>>& questions,vector<ll>&dp){
        if(i>=questions.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];

        ll take = questions[i][0] + solve(i+questions[i][1]+1,questions,dp);
        ll notTake = solve(i+1,questions,dp);
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size();
        vector<ll>dp(n+1,-1);
        return solve(0,questions,dp);
    }
};
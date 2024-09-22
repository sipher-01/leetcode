class Solution {
public:
    int solve(int i,int j, string s, string t,vector<vector<int>>&dp){
        if(i < 0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int p = 0;
        int np = 0;
        if(s[i]==t[j])p = 1 + solve(i-1,j-1,s,t,dp);
        else np = max(solve(i-1,j,s,t,dp),solve(i,j-1,s,t,dp));
        return dp[i][j] = np+p;
    }
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        int m = n;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return n-solve(n-1,m-1,s,t,dp);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1])dp[i][j] = 1 + dp[i-1][j-1];
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                } 
            }
        }
        int len = dp[n][m];
        return n - len;
    }
};
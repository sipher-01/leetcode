class Solution {
public:
    bool solve(int i, int j, string& s, string& p,vector<vector<int>>&dp){
        if(j==p.length())return i==s.length();
        bool match = (i < s.length() && (s[i]==p[j] || p[j]=='.'));
        bool res = false;
        if(dp[i][j]!=-1)return dp[i][j];
        if(j+1 < p.size() && p[j+1] == '*'){
            res = solve(i,j+2,s,p,dp) || (match && solve(i+1,j,s,p,dp));
        }
        else{
            res = match && solve(i+1,j+1,s,p,dp);
        }
        return dp[i][j] = res;
    }
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return solve(0,0,s,p,dp);
    }
};
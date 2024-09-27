class Solution {
public:
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string s,vector<int>&dp,int n){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int res = INT_MAX;
        for(int ind = i; ind<n; ind++){
            if(isPalindrome(i, ind, s)){
                int cuts = 1 + solve(ind+1,s,dp,n);
                res = min(res,cuts);
            }
        }
        return dp[i] = res;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        // return solve(0,s,dp,n)-1;
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int res = INT_MAX;
            for(int ind = i; ind<n; ind++){
                if(isPalindrome(i, ind, s)){
                    int cuts = 1 + dp[ind+1];
                    res = min(res,cuts);
                }
            }
            dp[i] = res;
        }
        return dp[0]-1;
    }
};
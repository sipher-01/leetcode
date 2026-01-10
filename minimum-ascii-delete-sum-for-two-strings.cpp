class Solution {
    vector<vector<int>>dp;
public:
    int solve(int i,int j, string s1, string s2){
        if(i==s1.length() || j == s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int val = 0;
        if(s1[i]==s2[j]){
            val = ((s1[i]- 'a') + 97)+ solve(i+1,j+1,s1,s2);
        }
        else{
            val = max(solve(i+1,j,s1,s2),solve(i,j+1,s1,s2));
        }
        return dp[i][j] = val;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        dp = vector<vector<int>>(s1.length()+1,vector<int>(s2.length()+1,0));
        int total = 0;
        int i=0,j=0;
        while(i<s1.length()){
            total += ((s1[i] - 'a') + 97); 
            i++;
        }
        while(j<s2.length()){
            total += (s2[j] - 'a') + 97;
            j++;
        }
        // int common = solve(0,0,s1,s2);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int val = 0;
                if(s1[i]==s2[j]){
                    dp[i][j] = ((s1[i]- 'a') + 97)+ dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int common = dp[0][0];
        int ans = total - 2* common;

        return ans;
    }
};
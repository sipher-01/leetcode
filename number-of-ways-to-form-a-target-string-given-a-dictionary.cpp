class Solution {
#define mod 1000000007
#define ll long long
private:
    vector<vector<int>>freq;
    vector<vector<int>>dp;
    int n,m;
public:
    int solve(int si,int ti, string target){
        if(ti>=m)return 1;
        if(si>=n || (n-si < m - ti))return 0;
        if(dp[si][ti]!=-1)return dp[si][ti];
        long long sum = solve(si+1,ti,target);
        int tarChar = target[ti] - 'a';
        if(freq[si][tarChar]>0){
                sum = (sum + (ll)freq[si][tarChar] * solve(si+1,ti+1,target))%mod; 
        }
        return dp[si][ti] = sum%mod;
    }
    int numWays(vector<string>& words, string target) {
        n = words[0].size();
        m = target.size();
        freq = vector<vector<int>>(n,vector<int>(26,0));
        for(auto const &word: words){
            for(int i=0; i<n; i++){
                freq[i][word[i]-'a']++;
            }
        }
        dp = vector<vector<int>>(1001,vector<int>(1001,-1));
        return solve(0,0,target);
    }
};
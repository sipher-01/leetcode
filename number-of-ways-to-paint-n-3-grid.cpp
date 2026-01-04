class Solution {
public:
    const int mod = 1e9+7;
    vector<string>base = {"RYR","RYG","RGR","RGY","YRY","YRG","YGR","YGY","GRY","GRG","GYR","GYG"};
    vector<vector<int>>dp;
    int solve(int n, int ind){
        if(n==0){
            return 1;
        }
        if(dp[n][ind]!=-1)return dp[n][ind];
        int res = 0;
        for(int i=0; i<12; i++){
            if(ind==i)continue;
            bool flag = false;
            for(int j=0; j<3; j++){
                if(base[ind][j]==base[i][j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                res = (res+solve(n-1,i))%mod;
            }
        }
        return dp[n][ind] = res%mod;
    }
    int numOfWays(int n) {
        int ans = 0;
        dp.resize(n+1,vector<int>(13,-1));
        for(int i=0; i<12; i++){
            ans = (ans + solve(n-1,i))%mod;
        }
        return ans;
    }
};
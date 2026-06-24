class Solution {
    int N,M;
    int mod = 1e9+7;
    // int dp[2001][2001][2];
    using ll = long long;

public:
    // int solve(int i, int prev, bool increasing){
    //     if(i==N){
    //         return 1;
    //     }
    //     int res = 0;
    //     if(dp[i][prev][increasing] != -1){
    //         return dp[i][prev][increasing];
    //     }
    //     if(increasing){
    //         for(int j = prev+1; j<=M; j++){
    //             res = (res + solve(i+1,j,false))%mod;
    //         }
    //     }
    //     else{
    //         for(int j = 1; j<prev; j++){
    //             res = (res + solve(i+1,j,true))%mod;
    //         }
    //     }
    //     return dp[i][prev][increasing] = res;
    // }
    int zigZagArrays(int n, int l, int r) {
        M = r - l + 1;
        N = n;
        ll dp[2001][2001][2];
        // memset(dp,0,sizeof(dp));
        for(int j=1; j<=M; j++){
            dp[N][j][1] = 1;
            dp[N][j][0] = 1;
        }
        ll res = 0;
        for(int i=N-1; i>=0; i--){
            vector<int>cs0(M+1,0);
            vector<int>cs1(M+1,0);

            for(int val=1; val<=M; val++){
                cs0[val] = (cs0[val-1] + dp[i+1][val][0])%mod;
                cs1[val] = (cs1[val-1] + dp[i+1][val][1])%mod;
            }

            for(int prev = 1; prev<=M; prev++){
                // for(int j = prev+1; j<=M; j++){
                //     dp[i][prev][1] = (dp[i][prev][1] + dp[i+1][j][0])%mod;
                // }
                dp[i][prev][1] = (cs0[M] - cs0[prev]+ mod) %mod;
                // for(int j = 1; j<prev; j++){
                //     dp[i][prev][0] = (dp[i][prev][0] + dp[i+1][j][1])%mod;
                // }
                dp[i][prev][0] = cs1[prev-1] ;
            }
        }
        for(int start = 1; start<=M; start++){
            // res = (res + solve(1,start,true))%mod; // increasing
            // res = (res + solve(1,start,false))%mod; // decreasing
            res = (res + dp[1][start][1])%mod;
            res = (res + dp[1][start][0])%mod;
        }

        return res;
    }
};
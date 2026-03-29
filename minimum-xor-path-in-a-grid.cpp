class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>temp = grid;

        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(1025,0)));

        // dp[0][0].insert(temp[0][0]);
        dp[0][0][grid[0][0]]=1;

        for(int j=1; j<n; j++){
            // for(auto xorr: dp[0][j-1]){
            //     dp[0][j].insert(xorr ^ temp[0][j]);
            // }
            for(int it=0; it<1025; it++){
                if(dp[0][j-1][it]==1){
                    dp[0][j][it^temp[0][j]] = 1;
                }
            }
        }

        for(int i=1; i<m; i++){
            // for(auto xorr: dp[i-1][0]){
            //     dp[i][0].insert(xorr ^ temp[i][0]);
            // }

            for(int it=0; it<1025; it++){
                if(dp[i-1][0][it]==1){
                    dp[i][0][it^temp[i][0]] = 1;
                }
            }
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){


                // for(auto xorr: dp[i-1][j]){
                //     dp[i][j].insert(xorr^temp[i][j]);
                // }
                for(int it=0; it<1025; it++){
                    if(dp[i-1][j][it]==1){
                        dp[i][j][it^temp[i][j]] = 1;
                    }
                }

                // for(auto xorr: dp[i][j-1]){
                //     dp[i][j].insert(xorr^temp[i][j]);
                // }
                
                for(int it=0; it<1025; it++){
                    if(dp[i][j-1][it]==1){
                        dp[i][j][it^temp[i][j]] = 1;
                    }
                }
            }
        }

        // int ans = *min_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
        for(int it=0; it<1025; it++){
            if(dp[m-1][n-1][it]==1){
                    return it;
            }
        }
        return -1;
    }
};
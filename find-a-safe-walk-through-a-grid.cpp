class Solution {
public:
    bool solve(int i, int j, vector<vector<int>>& grid,
     int health,int n,int m, vector<vector<int>>&visi,
     vector<vector<vector<int>>>&dp) 
    {
        visi[i][j]=1;
        if(health<1){
            visi[i][j]=0;
            return false;
        }
        if(i==n-1 && j==m-1){
            visi[i][j]=0;
            return true;
        }
        if(dp[i][j][health]!=-1){
            visi[i][j]=0;
            return dp[i][j][health];
        }
        int r[] = {-1,0,1,0};
        int c[] = {0,1,0,-1};
        bool pick = false;
        for(int ind=0; ind<4; ind++){
            int adjr = i + r[ind];
            int adjc = j + c[ind];
            if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && visi[adjr][adjc]==0){
                if(grid[adjr][adjc]==1){
                    if(health>1){
                        pick = solve(adjr,adjc,grid,health-1,n,m,visi,dp);
                        }
                }
                else{
                    pick = solve(adjr,adjc,grid,health,n,m,visi,dp);
                }
                if(pick)break;

            }
        }
        visi[i][j]=0;
        return dp[i][j][health]=pick ;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visi(n,vector<int>(m,0));
        if(grid[0][0]==1)health -= 1;
        vector<vector<vector<int>>>dp(n,
        vector<vector<int>>(m,vector<int>(health+1,-1)));
        return solve(0,0,grid,health,n,m,visi,dp);

        }
};
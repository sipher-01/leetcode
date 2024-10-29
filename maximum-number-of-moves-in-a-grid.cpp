class Solution {
    int ans = -1;
    int n,m;
public:
    bool valid(int r,int c){
        return r<n && r>=0 && c<m && c>=0;
    }
    int dfs(int r, int c,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(dp[r][c]!=-1)return dp[r][c];
        int move = 0;
        if(valid(r-1,c+1) && grid[r][c] < grid[r-1][c+1]){
            move = max(move,1 + dfs(r-1,c+1,grid,dp));
        }
        if(valid(r,c+1) && grid[r][c] < grid[r][c+1]){
            move = max(move,1 + dfs(r,c+1,grid,dp));
        }
        if(valid(r+1,c+1) && grid[r][c] < grid[r+1][c+1]){
            move = max(move,1 + dfs(r+1,c+1,grid,dp));
        }
        return dp[r][c] = move;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n+1,(vector<int>(m+1,-1)));
        for(int i=0; i<grid.size(); i++){
            ans = max(ans,dfs(i,0,grid,dp));
        }
        return ans;
    }
};
class Solution {
    int m,n;
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
public:
    bool isValid(int r, int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>&visi){
        visi[r][c] = true;
        int val = grid[r][c];
        for(int i=0; i<4; i++){
            int nr = r + row[i];
            int nc = c + col[i];
            if(isValid(nr,nc) && !visi[nr][nc] && grid[nr][nc]>0){
                val += dfs(nr,nc,grid,visi);
            }
        }
        return val;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visi(m,vector<bool>(n,false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visi[i][j] && grid[i][j]>0){
                    int fish = dfs(i,j,grid,visi);
                    ans = max(ans,fish);
                }
            }
        }
        return ans;
    }
};
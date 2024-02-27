class Solution {
private: 
    void DFS(vector<vector<int>>& grid, vector<vector<int>>& visi, int row, int col, int n, int m){
        visi[row][col]=2;
        int stepRow[] = {-1,0,1,0}; 
        int stepCol[] = {0,1,0,-1}; 
        for(int i=0; i<4; i++){
            int r = stepRow[i]+row;
            int c = stepCol[i]+col;
            if(r>=0 && r<n && c>=0 && c<m && visi[r][c]!=2 && grid[r][c]==1){
                DFS(grid,visi,r,c,n,m);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visi(n,vector<int>(m,0)); 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    visi[i][j]=2;
                }
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j]==1 &&  !visi[0][j]){
                DFS(grid,visi,0,j,n,m);
            }
            if(grid[n-1][j]==1 &&  !visi[n-1][j]){
                DFS(grid,visi,n-1,j,n,m);
            }
        }
        for(int i=1; i<n-1; i++){
            if(grid[i][0]==1 &&  !visi[i][0]){
                DFS(grid,visi,i,0,n,m);
            }
            if(grid[i][m-1]==1 &&  !visi[i][m-1]){
                DFS(grid,visi,i,m-1,n,m);
            }
        }
         for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && visi[i][j]==0){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    void swapRow(vector<vector<int>>& grid,int row,int n, int m){
        for(int i=0; i<m; i++){
            grid[row][i] ^= 1;
        }
    }
    void swapCol(vector<vector<int>>& grid,int col,int n, int m){
        for(int i=0; i<n; i++){
            grid[i][col] ^= 1;
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            if(grid[i][0]==0)swapRow(grid,i,n,m);
        }

        for(int j=1; j<m; j++){
            int ones=0;
            for(int i=0; i<n; i++){
                ones+=grid[i][j];
            }
            if(ones<=(n/2))swapCol(grid,j,n,m);
        }

        int total = 0;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<m; j++){
                sum += pow(2,m-j-1)*grid[i][j];
            }
            total+=sum;
        }
        return total;
    }
};
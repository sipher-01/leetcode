class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<int>>ans(m,vector<int>(n));
        int totalElements = m * n;
        
        k = k % totalElements; 

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int cur = i * n + j;
                int next = (cur + k) % totalElements;
                int ni = next/n;
                int nj = next%n;
                ans[ni][nj] = grid[i][j];
            }
        }
        return ans;
    }
};
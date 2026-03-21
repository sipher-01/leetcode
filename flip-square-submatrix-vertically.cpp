class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for(int j=y; j<y+k; j++){
            int l = x;
            int r = x+k-1;

            while(l<=r){
                int temp = grid[l][j];
                grid[l][j] = grid[r][j];
                grid[r][j] = temp;
                l++;
                r--;
            }
        }

        return grid;

    }
};
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>visi(m,(vector<int>(n,0)));
        vector<vector<int>>grid(m,(vector<int>(n,0)));
        for(auto it: guards){
            visi[it[0]][it[1]] = 1;
            grid[it[0]][it[1]] = 3;
        }
        for(auto it: walls){
            grid[it[0]][it[1]]=2;
            visi[it[0]][it[1]]=1;
        }
        for (auto& guard : guards) {
            int row = guard[0];
            int col = guard[1];

            // Move up
            int i = row-1;
            while (i >= 0 && grid[i][col] != 2 && grid[i][col]!=3) {
                visi[i][col] = 1;
                i--;
            }

            // Move down
            i = row+1;
            while (i < m && grid[i][col] != 2 && grid[i][col]!=3) {
                visi[i][col] = 1;
                i++;
            }

            // Move left
            int j = col-1;
            while (j >= 0 && grid[row][j] != 2 && grid[row][j]!=3) {
                visi[row][j] = 1;
                j--;
            }

            // Move right
            j = col+1;
            while (j < n && grid[row][j] != 2 && grid[row][j]!=3) {
                visi[row][j] = 1;
                j++;
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visi[i][j]==0)ans++;
            }
        }
        return ans;
    }
};
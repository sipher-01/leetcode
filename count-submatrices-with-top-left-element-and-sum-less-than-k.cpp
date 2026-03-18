class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans  = 0;
        if(grid[0][0]>k)return 0;
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        vector<int>row(m,0);
        for(int i=0; i<n; i++){
            int r = 0, d = 0;
            vector<int>temp(m,0);
            for(int j=0; j<m; j++){
                r += grid[i][j];
                temp[j] = r;
                if(i==0 && r<=k)ans++;
                if(j==0){
                    c += grid[i][j];
                    if(c<=k)ans++;
                }
                if(i>=1 && j>=1){
                    d = row[j] + r;
                    if(d<=k && d!=0)ans++;
                }
            }
            for(int j=0; j<m; j++){
                row[j] += temp[j];

            }
        }
        return ans-1;

    }
};
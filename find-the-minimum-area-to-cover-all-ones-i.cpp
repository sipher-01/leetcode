class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int min_x=n,max_x=0,min_y=m,max_y=0;
        for (int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (grid[i][j]==1){
                    max_y = max(max_y,j);
                    min_y = min(min_y,j);
                    max_x = max(max_x,i);
                    min_x = min(min_x,i);
                }
            }
        }
        cout<<max_x<<min_x<<max_y<<min_y;
        return ((max_x-min_x+1)*(max_y- min_y+1));
        
    }
};
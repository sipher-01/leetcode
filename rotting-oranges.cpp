class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int minTime=0;
    vector<vector<int>>visi(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    // {{r,c},t}
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visi[i][j]=grid[i][j];
            if(grid[i][j]==2){
              q.push({{i, j}, 0});
            }
        }
    }
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,-1,0,1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        minTime = max(minTime,t);
        q.pop();
        for(int j=0; j<4; j++){
            int nrow = r + drow[j];
            int ncol = c + dcol[j];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]!=2 && grid[nrow][ncol]==1){
              q.push({{nrow, ncol},t+1});
              visi[nrow][ncol] = 2;
            }
        }
    }
     for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visi[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return minTime;
    }
};
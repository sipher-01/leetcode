class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!= 0 )return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=1;
        q.push({1,{0,0}});
        int r[8] = {1,1,0,-1,-1,-1,0,1};
        int c[8] = {0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            if(row == n-1 && col == n-1)return dis;
            for(int i=0; i<8; ++i){
                int nr = row+r[i];
                int nc = col+c[i];
                if(nr<n && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==0 && 
                dist[nr][nc]>dis+1){
                        dist[nr][nc] = dis+1;
                        q.push({dist[nr][nc],{nr,nc}});
                }
            }

        }
        return -1;
    }
};
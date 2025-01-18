class Solution {
    int m,n;
public:
    bool isvalid(int row, int col){
        return row>=0 && row<m && col>=0 && col<n;
    }
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        deque<pair<int,int>>q;
        q.push_front({0,0});
        vector<vector<int>>visi(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0] = 0;
        int row[4] = {0,0,1,-1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()){
            auto node = q.front();
            q.pop_front();
            int r = node.first;
            int c = node.second;
            visi[r][c] = 1;
            int dir = grid[r][c]-1;
            for (int i = 0; i < 4; i++) {
                int nx = r + row[i];
                int ny = c + col[i];
                if(!isvalid(nx,ny) || visi[nx][ny])continue;
                int cost = dist[r][c] + (i == dir ? 0 : 1);
                if (cost < dist[nx][ny]) {
                    dist[nx][ny] = cost;
                    if (i == dir) q.push_front({nx, ny});
                    else q.push_back({nx, ny});
                }
            }
        }
        return dist[m-1][n-1];
    }
};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>> visi(n,(vector<int>(m,0)));
        visi[0][0]=1;
        int r[4] = {-1,0,1,0};
        int c[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int obs = node.first;
            int row = node.second.first;
            int col = node.second.second;
            if(row == n-1 && col == m-1)return obs;
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && visi[nr][nc]!=1){
                    if(grid[nr][nc]==1){
                        pq.push({obs+1,{nr,nc}});
                    }
                    else{
                        pq.push({obs,{nr,nc}});
                    }
                    visi[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};
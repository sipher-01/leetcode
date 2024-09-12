class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>>visi(n,vector<int>(n,0));
        visi[0][0]=1;
        int r[] = {1,0,-1,0};
        int c[] = {0,1,0,-1};
        while(!pq.empty()){
            int maxHeight = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1)return maxHeight;
            for(int i=0; i<4; i++){
                int adjr = row + r[i];
                int adjc = col + c[i];
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<n && !visi[adjr][adjc])
                {
                    visi[adjr][adjc]=1;
                    int newHeight = max(maxHeight, grid[adjr][adjc]);
                    pq.push({newHeight,{adjr,adjc}});
                }
            }

        }
        return -1;
    }
};
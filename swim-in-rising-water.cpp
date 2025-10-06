#define val pair<int,pair<int,int>> 
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<val,vector<val>,greater<val>>pq;
        vector<vector<int>>visi(n,vector<int>(n,0));
        pq.push({grid[0][0],{0,0}});
        int r[4] = {-1,0,1,0} ;
        int c[4] = {0,1,0,-1};
        while(!pq.empty()){
            int currTime = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1){
                return currTime;
            }
            for (int i=0; i<4; i++){
                int nr = r[i] + row;
                int nc = c[i] + col;
                if (nr>=0 && nr<n && nc>=0 && nc<n && !visi[nr][nc]){
                    int timeDiff = grid[nr][nc] - currTime;
                    timeDiff = timeDiff>0 ? timeDiff : 0;
                    visi[nr][nc] =1;
                    pq.push({currTime + timeDiff,{nr,nc}});
                }
            }
        }
        return -1;
    }
};
class Solution {
    #define p pair<int,pair<int,int>>
    int m,n;
public:
    bool isValid(int r, int c){
        return r>=0 && r<m && c>=0 && c<n;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        m = heightMap.size();
        n = heightMap[0].size();
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<vector<int>>visi(m,vector<int>(n,0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    pq.push({heightMap[i][j],{i,j}});
                    visi[i][j]=1;
                }
            }
        }
        int water = 0;
        int r[4] = {-1,0,1,0};
        int c[4] = {0,1,0,-1};
        while(!pq.empty()){
            auto [height,cod] = pq.top();
            auto [row,col] = cod;
            pq.pop();
            for(int i=0; i<4; i++){
                int nr = row + r[i];
                int nc = col + c[i];
                if(isValid(nr,nc) && !visi[nr][nc]){
                    water += max(height - heightMap[nr][nc],0);
                    visi[nr][nc] = 1;
                    pq.push({max(heightMap[nr][nc],height),{nr,nc}});
                }
            }

        }
        return water;
    }
};
class Solution {
    int m,n;
public:
    bool isValid(int r, int c){
        return r>=0 && r<m && c>=0 &&c<n;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        m = isWater.size();
        n = isWater[n].size();
        vector<vector<int>>visi(m,vector<int>(n,0));
        vector<vector<int>>height(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    visi[i][j] = 1;
                    q.push({0,{i,j}});
                }
            }
        }
        int row[4]={-1,0,1,0};
        int col[4]={0,1,0,-1};
        while(!q.empty()){
            auto [h,node] = q.front();
            q.pop();
            auto [r,c] = node;
            height[r][c] = h;
            for(int i=0; i<4; i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(isValid(nr,nc) && !visi[nr][nc]){
                    visi[nr][nc] =1;
                    q.push({h+1,{nr,nc}});
                }
            }
        }

        return height;
        
    }
};
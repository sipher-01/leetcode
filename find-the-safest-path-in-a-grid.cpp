// class Solution {
// public:

//     bool isValid(int r, int c, int n){
//         return r<n && r>=0 && c<n && c>=0;
//     }
//     int maximumSafenessFactor(vector<vector<int>>& grid) {

//         int n = grid.size();

//         queue<pair<int,int>>q;
//         vector<vector<int>>visi(n,vector<int>(n,0));
//         vector<vector<int>>arr(n,vector<int>(n,0));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==1){
//                     visi[i][j] = 1;
//                     q.push({i,j});
//                 }
//             }
//         }
//         int r[4] = {-1,0,1,0};
//         int c[4] = {0,1,0,-1};

//         while(!q.empty()){
//             auto [row,col] = q.front();
//             q.pop();
//             for(int i=0; i<4; i++){
//                 int nr = r[i] + row;
//                 int nc = c[i] + col;

//                 if(isValid(nr,nc,n) && !visi[nr][nc]){
//                     arr[nr][nc] = arr[row][col] + 1; 
//                     q.push({nr,nc});
//                 }
//             }
//         }

//         priority_queue<pair<int,pair<int,int>>>pq;
//         vector<vector<int>>dist(n,vector<int>(n,INT_MIN));
//         pq.push({arr[0][0],{0,0}});
//         dist[0][0] = arr[0][0];

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();
//             int val = it.first;
//             int row = it.second.first;
//             int col = it.second.second;
//             if(row == n-1 && col == n-1)return val;
//             for(int i=0; i<4; i++){
//                 int nr = row + r[i];
//                 int nc = col + c[i];

//                 int v = arr[nr][nc];
//                 if(isValid(nr,nc,n) && (min(val,v) > dist[nr][nc])){
//                     dist[nr][nc] = min(val,v);
//                     pq.push({dist[nr][nc],{nr,nc}});
//                 }
//             }
//         }

//         return dist[n-1][n-1];
        
//     }
// };

class Solution {
public:
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>arr(n,vector<int>(n,INT_MAX));
        vector<vector<int>>vis(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    vis[i][j]=1;
                    arr[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int>da{0,0,-1,1};
        vector<int>db{1,-1,0,0};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            for(int t=0;t<4;t++)
            {
                int ni=it.first+da[t];
                int nj=it.second+db[t];
                if(ni>=0 && nj>=0 && ni<n && nj<n && vis[ni][nj]==-1 && arr[it.first][it.second]+1<arr[ni][nj])
                {
                    vis[ni][nj]=1;
                    arr[ni][nj]=arr[it.first][it.second]+1;
                    q.push({ni,nj});
                }
            }
        }
        
        priority_queue<pair<int,pair<int,int>>>pq;
        vector<vector<int>> dist(n,vector<int>(n, INT_MIN));

        dist[0][0] = arr[0][0];
        pq.push({arr[0][0],{0,0}});
        
         while (!pq.empty())
        {
            int i = pq.top().second.first;
            int j=pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            for(int t=0;t<4;t++)
            {
                int ni=i+da[t];
                int nj=j+db[t];
                if(ni>=0 && nj>=0 && ni<n && nj<n)
                {
                    int w=arr[ni][nj];
                    if(min(w,dis)>dist[ni][nj])
                    {
                        dist[ni][nj]=min(w,dis);
                        pq.push({min(w,dis),{ni,nj}});
                    }
                }
            }
            
        }
        return dist[n-1][n-1];
        
    }
};
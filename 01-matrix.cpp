class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>>ans(n,vector<int>(m,0));
    vector<vector<int>>visi(n,vector<int>(m,0));
    //for row col and steps
    queue<pair<pair<int,int>,int>>q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j]==0){
              q.push({{i, j},0});
              visi[i][j]=1;
            }
        }
    }
    int rowStep[] = {-1,0,1,0};
    int colStep[] = {0,-1,0,1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        ans[row][col]=step;
        for(int i=0; i<4; i++){
            int nrow = row+rowStep[i];
            int ncol = col+colStep[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visi[nrow][ncol]==0){
                visi[nrow][ncol]=1;
                q.push({{nrow,ncol},step+1});
            }
        }

    }
    return ans;
    }
};
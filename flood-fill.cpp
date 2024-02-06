class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n=image.size();
    int m=image[0].size();
    vector<vector<int>>visi(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visi[i][j]=image[i][j];
        }
    }
    // change the curr value at x,y with p
    int curr = image[sr][sc];
    visi[sr][sc]=color;
    queue<pair<int,int>>q;
    q.push({sr,sc});
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, -1, 0, 1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int row = r+drow[i];
            int col = c+dcol[i];
            if(row>=0 && row<n && col>=0 && col<m && visi[row][col]!=color && image[row][col]==curr){
                visi[row][col]=color;
                q.push({row,col});
            }
        }
    }
    return visi;
    }
};
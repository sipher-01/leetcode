class Solution {
    private:
    void DFS(vector<vector<char>>& arr,vector<vector<int>>&visi,int row, int col, int n, int  m){
    visi[row][col]=1;
    int nRow[] = {-1,0,1,0};
    int nCol[] = {0,1,0,-1};
    for(int i=0; i<4; i++){
        int r = nRow[i]+row;
        int c = nCol[i]+col;
        if(r>=0 && r<n && c>=0 && c<m && visi[r][c]==0 && arr[r][c]=='O'){
            DFS(arr,visi,r,c,n,m);
        }
    }

} 
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
            vector<vector<int>>visi(n,vector<int>(m,0));
    for(int j=0; j<m; j++){
            if(board[0][j]=='O'){
                if(!visi[0][j])DFS(board,visi,0,j,n,m);
            }
            if( board[n-1][j]=='O'){
                if(!visi[n-1][j])DFS(board,visi,n-1,j,n,m);
            }
    }
    for(int i=1; i<n-1; i++){
        if(board[i][0]=='O'){
            if(!visi[i][0])DFS(board,visi,i,0,n,m);
        }
        if(board[i][m-1]=='O'){
            if(!visi[i][m-1])DFS(board,visi,i,m-1,n,m);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O' && visi[i][j]==0){
                board[i][j]='X';
            }
        }
    }
    }
};
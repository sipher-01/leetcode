class Solution {
public:
    bool check(int r, int c, int n, int m,vector<vector<int>>& mat){
        for(int i=0; i<m; i++){
            if(i==r)continue;
            if(mat[i][c]==1)return false;
        }
        for(int j=0; j<n; j++){
            if(j==c)continue;
            if(mat[r][j]==1)return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int cnt = 0;

        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1 && check(i,j,n,m,mat)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
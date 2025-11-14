class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for (auto it:queries){
            int row1 = it[0], row2 = it[2];
            int col1 = it[1], col2 = it[3];
            for(int i=row1; i<=row2; i++){
                mat[i][col1] += 1;
                if(col2+1<n)mat[i][col2 + 1] -= 1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                mat[i][j] += mat[i][j-1];
            }
        }
        return mat;
    }
};
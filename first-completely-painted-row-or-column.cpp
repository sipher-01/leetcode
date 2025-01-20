class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>position;
        int m = mat.size();
        int n = mat[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                position[mat[i][j]] = {i,j};
            }
        }

        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0; i<arr.size(); i++){
            auto [r,c] = position[arr[i]];
            row[r]++;
            col[c]++;
            if(row[r]==n || col[c]==m){
                return i;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();

        for(int j = 0; j<m; j++){
            int ones = 0;
            for(int i=0; i<n; i++){
                ones = matrix[i][j]==1?ones+1:0;
                matrix[i][j] = ones;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            int j;
            int h = INT_MAX;
            for( j=0; j<m && matrix[i][j]>0; j++){
                h = min(h,matrix[i][j]);
                ans = max(ans,h*(j+1));
            }
        }
        return ans;
    }
};
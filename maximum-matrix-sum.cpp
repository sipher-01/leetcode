class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int neg = 0;
        long long total = 0;
        int min_ele = INT_MAX;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]<0)neg++;
                total += abs(matrix[i][j]);
                min_ele = min(min_ele,abs(matrix[i][j]));
            }
        }
        if(neg%2==0)return total;
        else{
            return (total - (min_ele*2));
        }
    }
};
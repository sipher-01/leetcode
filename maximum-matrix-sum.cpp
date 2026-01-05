class Solution {
public:
    using ll = long long;
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll ans = 0;
        ll neg = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        int zero = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                else if(matrix[i][j]==0){
                    zero = true;
                }
                ll num = abs(matrix[i][j]);
                neg = min(neg,num);
                ans += num;
            }
        }
        if(cnt%2 && !zero){
            ans -= (2*neg);
        }
        return ans;
    }
};
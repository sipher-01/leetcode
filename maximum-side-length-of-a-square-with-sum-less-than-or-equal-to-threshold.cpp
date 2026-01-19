class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int side = min(m,n);
        int num = INT_MAX;
        vector<vector<int>>row(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            row[i][0] = mat[i][0];
            num = min(num,mat[i][0]);
            for(int j=1; j<m; j++){
                num = min(num,mat[i][j]);
                row[i][j] = row[i][j-1] + mat[i][j];
            }
        }
        auto lambda = [row,&threshold,&n,&m](int s)
        {   for(int i=0; i<n-s+1; i++){
                for(int j=0; j<m-s+1; j++){
                    int sum = 0;
                    for(int k=i; k<i+s; k++){
                        int val = row[k][j+s-1] - (j>0?row[k][j-1]:0);
                        sum += val;
                    }
                    if(sum<=threshold){
                        return s;
                    }
                }
            }
            return -1;
        };
        int l = 1, h=side;
        int res;
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            res = lambda(mid);
            if(res!=-1){
                ans = max(res,ans);
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }

        return ans;
    }
};
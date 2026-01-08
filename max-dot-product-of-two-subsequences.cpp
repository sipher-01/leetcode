class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        if( i==nums1.size()){
            if(j==0)return INT_MIN;
            else return 0;
        }
        if(j==nums2.size()){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi = INT_MIN;
        for(int k=j ; k<nums2.size(); k++){
            maxi = max(maxi,(nums1[i]*nums2[k])+solve(i+1,k+1,nums1,nums2));
        }
        maxi = max(maxi,solve(i+1,j,nums1,nums2));
        return dp[i][j] = maxi;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        dp = vector<vector<int>>(n+1, vector<int>(m+1,-1));
        int ans = solve(0,0,nums1,nums2);
        return ans;
    }
};
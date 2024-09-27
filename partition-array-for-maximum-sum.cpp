class Solution {
public:
    int solve(int i, int k, vector<int>& arr, vector<int>&dp){
        int n = arr.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int maxSum = 0;
        int len = 0;
        int maxi = INT_MIN;
        for(int j=i; j < min(i+k,n); j++){
            len++;
            // int maxEle = *max_element(arr.begin()+i,arr.begin()+j+1);
            maxi = max(maxi,arr[j]);
            int sum = maxi*len + solve(j+1,k,arr,dp);
            maxSum = max(maxSum,sum);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,k,arr,dp);
    }
};
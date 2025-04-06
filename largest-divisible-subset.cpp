class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        // vector<int>res,hash(n),dp(n,1);
        // int ans = 1,lastInd = 0;
        // for(int i=1; i<n; i++){
        //     hash[i] = i;
        //     for(int j=0; j<i; j++){
        //         if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
        //             dp[i] = 1+dp[j];
        //             hash[i] = j;
        //         }
        //     }
        //     if(ans<dp[i]){
        //         ans = dp[i];
        //         lastInd = i;
        //     }
        // }
        // while(hash[lastInd]!=lastInd){
        //     res.push_back(nums[lastInd]);
        //     lastInd = hash[lastInd];
        // }
        // res.push_back(nums[lastInd]);
        // return res;
        vector<vector<int>>dp(n);
        vector<int>res;
        for (int i = 0; i < n; ++i) {
            dp[i] = {nums[i]};
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j].size() + 1 > dp[i].size()) {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }
            }
            if (dp[i].size() > res.size()) {
                res = dp[i];
            }
        }
        return res;
    }
};
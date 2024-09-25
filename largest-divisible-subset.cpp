class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>res,hash(n),dp(n,1);
        int ans = 1,lastInd = 0;
        for(int i=1; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i] = 1+dp[j];
                    hash[i] = j;
                }
            }
            if(ans<dp[i]){
                ans = dp[i];
                lastInd = i;
            }
        }
        while(hash[lastInd]!=lastInd){
            res.push_back(nums[lastInd]);
            lastInd = hash[lastInd];
        }
        res.push_back(nums[lastInd]);
        return res;
    }
};
class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>&dp){
        if(target==0)return true;
        if(i==0) return nums[i]==target;
        if(dp[i][target]!=-1)return dp[i][target];
        bool notPick = solve(i-1,target,nums,dp);
        bool pick = false;
        if(target>=nums[i])pick = solve(i-1,target-nums[i],nums,dp);

        return dp[i][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(total_sum%2==1)return false;
        vector<vector<int>>dp(n+1,vector<int>(total_sum/2+1,-1));
        return solve(n-1,total_sum/2,nums,dp);
    }
};
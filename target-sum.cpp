class Solution {
public:
    int solve(int ind,int sum, int total, int target, vector<int>& nums,
            unordered_map<string,int>&dp){
        //    vector<vector<int>>&dp){
        if(ind == 0){
            if((sum + nums[ind] == target || sum - nums[ind] == target) &&
             nums[0]==0)return 2;
            if(sum + nums[ind] == target || sum - nums[ind] == target)return 1;
            else return 0;
        }
        string key = to_string(ind) + '#' + to_string(sum);
        // if(dp[ind][sum + total]!=-1)return dp[ind][sum+total];
        if(dp.count(key))return dp[key];
        int sub = 0, add = 0;
        sub =  solve(ind-1,sum - nums[ind],total,target,nums,dp);
        add =  solve(ind-1,sum + nums[ind],total,target,nums,dp);

        // return dp[ind][sum+total] = add + sub;
        return dp[key] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  =  nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>total)return 0;
        // vector<vector<int>>dp(n,vector<int>(2*total+1,-1));
        unordered_map<string,int>dp;
        return solve(n-1,0,total,target,nums,dp);
    }
};
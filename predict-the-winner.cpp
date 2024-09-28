class Solution {
public:
    int solve(int i, int j,int turn, vector<int>&nums, vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans= 0;
        if(turn){
            ans = max(nums[i]+solve(i+1,j,0,nums,dp),
            nums[j]+solve(i,j-1,0,nums,dp));
        }
        else{
            ans = min(-nums[i]+solve(i+1,j,1,nums,dp),
            -nums[j]+solve(i,j-1,1,nums,dp));
        }
        return dp[i][j] = ans;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        if(n&1)return (solve(0,n-1,1,nums,dp)>=0);
        return true;
    }
};
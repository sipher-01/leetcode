class Solution {
    int ans = 0;
public:
    void solve(int i, vector<int>&nums, int target, int orr){
        
        if(i<0){
            if(orr == target){
            ans++;
            }
            return ;
        }
        solve(i-1,nums,target,orr);
        solve(i-1,nums,target,orr|nums[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        for(int i=1; i<nums.size(); i++){
            a |= nums[i];
        }
        solve(n-1,nums,a,0);
        return ans;
    }
};
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int r=0; r<=n-3; r++){
            if(nums[r+1]%2==0 && (nums[r]+nums[r+2]==nums[r+1]/2))ans++;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int left = 0;
        for(int i=0; i<n; i++){
            int right = total - left - nums[i];
            int sum = abs(left - right);
            ans.push_back(sum);
            left += nums[i];
        }

        return ans;
    }
};
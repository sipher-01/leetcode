class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++){
            sum = max(sum+nums[i],nums[i]);
            maxSum = max(maxSum,sum);
        }
        int minSum = nums[0];
        sum = nums[0];
        for(int i=1; i<n; i++){
            sum = min(sum+nums[i],nums[i]);
            minSum = min(minSum,sum);
        }
        minSum = abs(minSum);
        if(maxSum>minSum)return maxSum;
        return minSum;
    }
};
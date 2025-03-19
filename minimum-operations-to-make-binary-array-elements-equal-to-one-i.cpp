class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        int n = nums.size();
       for (int i = 2; i < nums.size(); i++) {
            // only looking forward to the last element
            if (nums[i - 2] == 0) {
                op++;
                // flip i-2 and i-1 and i
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size()) return op;
        return -1;
    }
};
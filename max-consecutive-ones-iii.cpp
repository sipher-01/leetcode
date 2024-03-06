class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
    int length = 0;
    int n = nums.size();
    int left = 0, right = 0;
    int zeroCount = 0;
    while(right<n){
        if (nums[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        length = max(length, right - left + 1);
        right++;
    }
    return length;
    }
};
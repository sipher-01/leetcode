class Solution {
public:
    int countNegatives(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1, firstZero = n;

        // Find the first zero (or first positive if no zero exists)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= 0) {
                firstZero = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return firstZero;  // Count of negative numbers
    }

    int countPositives(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1, firstPositive = n;

        // Find the first positive number
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > 0) {
                firstPositive = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return n - firstPositive;  // Count of positive numbers
    }
    int maximumCount(vector<int>& nums) {
        return max(countPositives(nums),countNegatives(nums));
    }
};
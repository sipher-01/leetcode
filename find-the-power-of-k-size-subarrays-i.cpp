class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
           bool isContinuous = true;
            int maxVal = nums[i];

            // Check continuity in the subarray [i, i+k-1]
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] != nums[j - 1] + 1) {
                    isContinuous = false;
                    break;
                }
                maxVal = max(maxVal, nums[j]);
            }

            if (isContinuous) {
                ans.push_back(maxVal);
            } else {
                ans.push_back(-1);
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;

        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());

        ans = (long long)(mx- mn) * k;

        return ans;
    }
};
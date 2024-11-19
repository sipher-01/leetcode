class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = 0;
        int n = nums.size();
        if(n<k)return 0;
        unordered_map<int,int>mp;
        int i=0, j=0;
        while(j<n){
            while(mp[nums[j]]!=0 && i<j){
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            sum += nums[j];
            if(j-i+1 == k){
                ans = max(ans,sum);
                sum -= nums[i];
                mp[nums[i]]--;
                i++;
            }
            mp[nums[j]]++;
            j++;
        }
        return ans;
    }
};
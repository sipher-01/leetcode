class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long cnt = 0;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int diff = nums[i]-i;
            int gpair = mp[diff];
            cnt += i - gpair;
            mp[diff]++;
        }
        return cnt;
    }
};
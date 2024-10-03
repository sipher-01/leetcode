class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        long long sum = accumulate(nums.begin(),nums.end(),0ll);
        int target = sum%p;
        if(target==0)return 0;
        unordered_map<int,int>prefix;
        prefix[0]=-1;
        long long prefixSum = 0;
        int len=n;
        for(int i=0; i<n; i++){
            prefixSum += nums[i];
            int curr = prefixSum % p;
            int want = (curr - target + p)%p;
            if(prefix.find(want)!=prefix.end()){
                len = min(len,i-prefix[want]);
            }
            prefix[curr]=i;
        }

       return len == nums.size() ? -1 : len;
    }
};
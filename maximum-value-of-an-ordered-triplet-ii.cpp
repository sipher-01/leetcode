class Solution {
public:
    using ll = long long;
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        ll maxDiff = 0;
        ll max_i = 0;
        ll n = nums.size();
        for(int i=0; i<n; i++){
            ans = max(ans,(maxDiff*nums[i]));
            maxDiff = max(maxDiff,max_i - nums[i]);
            max_i = max(max_i,(ll)nums[i]);
        }
        return ans;
    }
};
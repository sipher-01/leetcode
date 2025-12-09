class Solution {
public:
    const int mod = 1e9+7;

    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>partial_mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(int v: nums){
            int target = v*2;
            int left = partial_mp[target];
            partial_mp[v]++;
            int right = mp[target] - partial_mp[target];
            int ad = (right*1LL*left)%mod;
            ans = (ans%mod+ad)%mod;
        }
        return ans;
    }
};
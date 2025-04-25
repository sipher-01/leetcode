class Solution {
public:
    using ll = long long;
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        
        unordered_map<int,int>mp;
        ll prefix = 0;
        ll ans = 0;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%modulo == k){
                prefix++;
                prefix%=modulo;
            }
            if(mp.find((prefix-k+modulo)%modulo)!=mp.end()){
                ans += mp[(prefix-k+modulo)%modulo];
            }
            mp[prefix]++;
        }

        return ans;
    }
};
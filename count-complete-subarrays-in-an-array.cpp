class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int unique = 0;
        unordered_map<int,int>mp;
        for(auto it: nums){
            mp[it]++;
        }
        unique = mp.size();
        mp.clear();
        int l=0,r=0;
        int n = nums.size();
        int ans = 0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()==unique){
                ans += (n-r);
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};
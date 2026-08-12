class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int l = 0;
        int mx = 0;
        for(int r=0; r<n; r++){
            mp[nums[r]]++;
            while(l<r && mp[nums[r]]>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            mx = max(mx, r-l+1);
        }


        return mx;
    }
};
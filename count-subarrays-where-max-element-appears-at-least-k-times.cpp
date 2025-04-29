class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0,r=0;
        int maxi = *max_element(begin(nums),end(nums));
        int count = 0;
        ll ans = 0;
        while(r<n){
            if(maxi == nums[r])count++;
            while(count==k){
                if(nums[l]==maxi)count--;
                l++;
            }
            ans+=l;
            r++;
        }
        return ans;
    }
};
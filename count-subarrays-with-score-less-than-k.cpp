class Solution {
public:
    using ll = long long;
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        ll sum = 0;
        ll ans = 0;

        int i=0,j=0;
        while(j<n){
            sum += nums[j];

            while(sum*(j-i+1)>=k){
                sum -= nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }

        return ans;
    }
};
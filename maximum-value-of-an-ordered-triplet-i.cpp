class Solution {
public:
    using ll = long long;
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){

                    ans = max(ans,(ll)(nums[i]-nums[j])*nums[k]);
                }
            }

        }
        return ans;
    }
};
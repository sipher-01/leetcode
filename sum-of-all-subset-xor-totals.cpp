class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 1<<n;
        int ans = 0;
        for(int mask=0; mask<total; mask++){
            int xor_subset = 0;
            for(int i=0; i<n; i++){
                if(mask & (1<<i)){
                    xor_subset ^= nums[i];
                }
            }
            ans += xor_subset;
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int a = 0;
        vector<int>xorr;
        for(int i=0; i<nums.size(); i++){
            a ^= nums[i];
            xorr.push_back(a);
        }
        vector<int>ans;
        int mask = (1<<maximumBit)-1;
        for(int i=n-1; i>=0; i--){
            int flip = xorr[i]^mask;
            ans.push_back(flip);
        }
        return ans;
    }
};
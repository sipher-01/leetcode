class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 1;
        int l = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<=nums[i-1]){
                l = i;
            }
            len = max(len,i-l+1);
        }
        return len;
    }
};
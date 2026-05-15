class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(((i+1) != nums[i]) && (i!=n-1))return false;
            else if(i==n-1 && nums[i]==n-1)return true;
        }
        return false;
    }
};
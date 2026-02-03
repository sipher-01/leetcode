class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1,q=-1;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i-1] >= nums[i] && p==-1){
                return false;
            }
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                if(p==-1)p=i;
                else return false;
            }
            if(nums[i-1] > nums[i] && nums[i] < nums[i+1] && p!=-1){
                if(q==-1)q = i;
                else return false;
            }
            if(nums[i]>=nums[i+1] && p!=-1 && q!=-1)return false;
        }
        if(p!=-1 && q!=-1)return true;
        return false;
    }
};
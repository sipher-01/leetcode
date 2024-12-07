class Solution {
public:
    bool isPossible(vector<int>&nums,int op, int x){
        int total_op = 0;
        for(int &it: nums){
            total_op += (it%x==0)?it/x - 1: it/x;
            if(total_op>op)return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int n = nums.size();
        int r = *max_element(nums.begin(),nums.end());
        while(l<=r){
            int mid = (l+r)/2;
            if(isPossible(nums,maxOperations,mid)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
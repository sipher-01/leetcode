class Solution {
private: 
    int bs(vector<int>& nums, int x){
        int l=0,r=nums.size()-1;
        int ans = 0;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]<=x){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return ans;
    }
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0;
        // for(int i=0; i<nums.size(); i++){
        //     int end = bs(nums,nums[i]+ 2*k);
        //     res = max(res,end-i+1);
        // }
        int i=0, j=0;
        while(i<nums.size()){
            while(j<nums.size() && nums[j]<= nums[i] + (2*k)){
                j++;
            }
            res = max(res,j-i);
            i++;
        }
        return res;
    }
};
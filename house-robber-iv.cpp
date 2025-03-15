class Solution {
public:
    bool check(vector<int>&nums,int mid,int k){
        int cnt = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }
        return k<=cnt;
    }
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(nums,mid,k)){
                ans = min(ans,mid);
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    // int upperBound(vector<int>& nums,int l,int r,int n){
    //     while(l<r){
    //         int mid = (l+r)/2;
    //         if(nums[mid]<=n){
    //             l = mid+1;
    //         }
    //         else{
    //             r = mid;
    //         }
    //     }
    //     return l;
    // }
     int upperBound(vector<int>& nums, int l, int r, int n) {
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
    int lowerBound(vector<int>& nums,int l,int r,int n){
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]<n){
                l = mid+1;
            }
            else{
                r= mid;
            }
        }
        return l;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
     long long ans = 0;
     sort(nums.begin(),nums.end());
     int n = nums.size();
     for(int i=0; i<nums.size()-1; i++){
        auto  a = upperBound(nums,i+1,n,upper-nums[i]);
        auto b = lowerBound(nums,i+1,n,lower-nums[i]);
        ans += (a-b);
     }   
     return ans;
    }
};
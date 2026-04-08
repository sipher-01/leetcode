class SegmentTree{
// vector<int>arr;

// public: 
//     SegmentTree(int n):arr(4*n+1){

//     }

//     int create(vector<int>& nums, int l,  int r, int i){
//         if(l==r)return nums[l];
//         else{
//             int mid = (l+r)/2;
//             int left = create(nums,l,mid, 2*i+1);
//             int right = create(nums,mid+1,r, 2*i+2);
//             arr[i] = left^right;
//         }
//     }
};

class Solution {
    const int mod = 1e9+7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // SegmentTree s(n);

        for(auto it: queries){
            int l = it[0];
            int r = it[1];
            int gap = it[2];
            int k = it[3];
            for(int i=l; i<=r; i+= gap){
                nums[i] = (1LL*nums[i]*k)%mod; 
            }
        }
        int ans = 0;
        for(auto it: nums){
            ans ^= it;
        }
        return ans;
    }
};
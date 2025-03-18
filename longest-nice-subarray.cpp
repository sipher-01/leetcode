class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        // vector<int>bits(31,0);
        int l=0;
        int ans = 1;
        int mask =0;
        int n = nums.size();
        for(int r=0; r<n; r++){
            // for(int i=0; i<=30; i++){
            //     if(nums[r] & (1<<i)){
            //         bits[i]++;
            //         while(bits[i]>1){
            //             for(int j=0; j<=30; j++){
            //                 if(nums[l]&(1<<j))bits[j]--;
            //             }
            //             l++;
            //         }
            //     }
            // }
            while((mask&nums[r])!=0){
                mask ^=nums[l];
                l++;
            }
            mask |= nums[r];
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
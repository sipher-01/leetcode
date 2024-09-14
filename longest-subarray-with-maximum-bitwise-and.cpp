class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0; 
        int n = nums.size();
        int maxA = *max_element(nums.begin(),nums.end());
        int maxi = 0;
        int cnt = 0;
        while(i<n){
            if(maxA == nums[i]){
                while(i<n && maxA == nums[i]){
                    cnt++;
                    i++;
                }
                maxi = max(maxi,cnt);
            }
            else{
            i++;
            cnt=0;
            }
        }
        return maxi;

    }
};
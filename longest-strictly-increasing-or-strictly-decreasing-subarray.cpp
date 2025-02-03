class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si = 1;
        int sd = 1;
        int n = nums.size();
        int l=0;
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                l = i;
                continue;
            }
            si = max(si,i-l+1);
        }
        cout<<si<<endl;
        l=0;
        for(int i=1; i<n; i++){
            if(nums[i]>=nums[i-1]){
                l = i;
                continue;
            }
            sd = max(sd,i-l+1);
        }
        cout<<sd<<endl;
        return max(si,sd);
    }
};
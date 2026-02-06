class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0;
        int cnt = 1;
        for(int i=1; i<nums.size(); i++){

            while((long long)nums[i] > (long long)nums[l]*k){
                l++;
            }
            cnt = max(cnt,i-l+1);
        }
        return nums.size() - cnt;
        
    }
};
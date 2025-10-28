class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        
        int total_sum = accumulate(nums.begin(),nums.end(),0);
        int curr = 0;
        int ans = 0;

        for(int i=0; i<nums.size(); i++){
            curr += nums[i];
            int leftover = total_sum - curr;
            if(nums[i]==0 && (curr == leftover)){
                ans += 2;
            }
            else if(nums[i]==0 && abs(curr - leftover) == 1){
                ans += 1;
            }
        }

        return ans;

    }
};
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        set<int>st(nums.begin(), nums.end());
        int n = nums.size();
        int sum = nums[0];
        int mx_sum = nums[0];
        for(int i=1; i<n; i++){

            if((nums[i] == nums[i-1]+1)){
                sum += nums[i];
            }
            else break;
            mx_sum = max(mx_sum, sum);
        }
        while(st.count(mx_sum)>0){
            mx_sum++;
        }

        return mx_sum;
    }
};
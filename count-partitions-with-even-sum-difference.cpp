class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int front = nums[0];
        int ans = 0;
        for(int i=1; i<nums.size(); i++){
            int last = sum - front; 
            int diff = abs(last - front);
            if(diff%2==0)ans++;
        }
    return ans;
    }
};
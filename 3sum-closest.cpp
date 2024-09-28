class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closeSum = 1e9;
        for(int i=0; i<n; i++){
            //while(i>0 && nums[i]==nums[i-1])continue;
            int j=i+1, k = n-1;
        while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(closeSum-target)>abs(sum-target)){
                    closeSum = sum;
                }
                if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else {
                    return sum;
                }
               // while(j<k && nums[j]==nums[j-1])continue;
               // while(j<k && nums[k]==nums[k+1])continue;
            }
        }
         return closeSum;   
    }
};
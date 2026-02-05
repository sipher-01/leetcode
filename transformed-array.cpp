class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n);
        for(int i=0; i<n; i++){
            if(nums[i]<0){
                int steps = abs(nums[i])%n;
                int left = i - steps;
                int ind = left<0?n+left:left;
                if(ind>=0 && ind<n) res[i] = nums[ind]; 
            }
            else if(nums[i]>0){
                int steps = nums[i]%n;
                int right = i + steps;
                int ind = right>=n?right-n:right;
                if(ind>=0 && ind<n)res[i] = nums[ind];
            }
        }
        return res;
    }
};
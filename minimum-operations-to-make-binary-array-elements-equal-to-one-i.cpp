class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                if(i+2>=n)break;
                int k = 0;
                op++;
                while(i+k<n && k<3){
                    nums[i+k] ^= 1;
                    k++; 
                }
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]==0)return -1;
            cout<<nums[i]<<" ";
        }
        return op;
    }
};
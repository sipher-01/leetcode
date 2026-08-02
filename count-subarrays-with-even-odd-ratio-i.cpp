class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        float ratio = (float)a/b;
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            float odd = 0;
            float even = 0;
            for(int j=i; j<n; j++){
                if(nums[j]&1){
                    odd++;
                }
                else even++;
                if((odd > 0) && (even*b <= odd*a)){
                    // cout<<format("i : {} j : {}",i,j)<<endl;
                    // cout<<format("odd : {} even : {}",odd,even)<<endl;
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};
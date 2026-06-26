class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        int c = 0;
        vector<int>count(n);
        for(int i=0; i<n; i++){
            if(nums[i]==target)c++;
            count[i] = c;
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int cnt = 0;
                int l = j-i+1;
                // for(int k=i; k<=j; k++){
                //     if(nums[k] == target){
                //         cnt++;
                //     }
                // }
                cnt = count[j] - (i-1<0?0:count[i-1]);
                if(cnt > l/2)ans++;
            }
        }

        return ans;
    }
};
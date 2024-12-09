class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<bool>ans;
        vector<int>cumSum;
        int cnt = 0;
        cumSum.push_back(0);
        int n = nums.size();
        for(int i=1; i<n; i++){
            if((nums[i-1]%2==0 && nums[i]%2==0)||(nums[i-1]%2!=0 && nums[i]%2!=0)){
                cnt++;
                cumSum.push_back(cnt);
            }
            else{
                cumSum.push_back(cnt);
            }
        }

        for(auto it: queries){
            if(cumSum[it[1]]-cumSum[it[0]]==0)ans.push_back(true);
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
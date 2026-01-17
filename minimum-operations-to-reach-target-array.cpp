class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int op = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            if(nums[i]!=target[i]){
                op++;
                mp[nums[i]]++;
            }
        }
        for(auto &it: mp){
            if(it.second>1){
                op = op - it.second + 1;
            }
        }
        return op;
    }
};
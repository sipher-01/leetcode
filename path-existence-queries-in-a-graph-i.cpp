class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int compId = 0;
        vector<int>comp(n,-1);
        comp[0] = compId;
        for(int i=1; i<n; i++){
            if(abs(nums[i-1] - nums[i]) <= maxDiff){
                comp[i] = compId;
            }
            else{
                compId++;
                comp[i] = compId;
            }
        }
        vector<bool>ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            if(comp[u]==comp[v]){
                ans.push_back(true);
            }
            else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
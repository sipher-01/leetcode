class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it: queries){
            int xorr = 0;
            for(int i = it[0]; i<=it[1]; i++){
                xorr ^= arr[i];
            }
            ans.push_back(xorr);
        }
        return ans;
    }
};
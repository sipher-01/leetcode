class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
     unordered_map<string,int>mp;
     int m = matrix.size();
     int n = matrix[0].size();
     for(auto &row: matrix){
        string nature = "";
        int first = row[0];
        for(int &col: row){
            nature += (col == first)?'S':'B';
        }
        mp[nature]++;
     }  
     int ans = 0;
     for(auto &it: mp){
        ans = max(ans,it.second);
     } 
     return ans;
    }
};
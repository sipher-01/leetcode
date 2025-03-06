class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2,0);
        unordered_map<int,int>mp;
        int n = grid.size();
        int m = n*n;
        for(int i=1; i<=m; i++){
            mp[i] = 0;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]]++;
            }
        }
        for(int i=1; i<=m; i++){
            if(mp[i]==2){
                ans[0]=i;
            }
            else if(mp[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};
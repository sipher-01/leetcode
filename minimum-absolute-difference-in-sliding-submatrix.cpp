class Solution {

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        // ios::sync_with_stdio(false);
        // cin.tie(NULL);
        vector<vector<int>>ans;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            vector<int>temp;
            for(int j=0; j<m; j++){
                int nn = i + k;
                int nm = j + k;
                if(nn<=n && nm<=m){
                    set<int>st;
                    for(int k = i; k<nn; k++){
                        for(int l = j; l<nm; l++){
                            st.insert(grid[k][l]);
                        }
                    }
                    int mini = INT_MAX;
                    for(auto it = next(st.begin()); it!=st.end(); it++){
                        int first = *it;
                        int second = *prev(it);
                        mini = min(mini, abs(second - first));
                    }
                    if(mini == INT_MAX) mini = 0;
                    temp.push_back(mini);
                }
            }
            if(temp.size()>0)ans.push_back(temp);
        }

        return ans;
    }
};
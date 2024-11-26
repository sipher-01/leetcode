class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        for(auto it: edges){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++){
            adj[i].push_back(000);
        }
        int ans = -1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(adj[i].size()==1){
                ans = i;
                cnt++;
            }
        }

        if(cnt!=1)return -1;
        return ans;
    }
};
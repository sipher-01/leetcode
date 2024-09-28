class Solution {
    int timer = 1;
    void dfs(int node, int parent, int low[], int tin[],vector<int>adj[],
    vector<vector<int>>&bridge,vector<int>&visi){
        visi[node]=1;
        low[node] = tin[node] = timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent)continue;
            if(visi[it]==0){
                dfs(it,node,low,tin,adj,bridge,visi);
                low[node] = min(low[node],low[it]);
                if(low[it]>tin[node]){
                    bridge.push_back({node,it});
                }
            }
            else{
                low[node] = min(low[it],low[node]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int low[n];
        int tin[n];
        vector<int>visi(n,0);
        vector<vector<int>>bridge;
        dfs(0,0,low,tin,adj,bridge,visi);
        return bridge;
    }
};
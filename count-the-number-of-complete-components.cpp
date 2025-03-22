class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>>&adj, int &nodes, int &edges,vector<bool>&visi){
        visi[i] = true;
        nodes+=1;
        for(auto it: adj[i]){
            edges+=1;
            if(!visi[it]){
                dfs(it,adj,nodes,edges,visi);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);
        int ans = 0;
        for(int i=0; i<n; i++){
            int nodes = 0, edges=0;
            if(!visited[i]){
                dfs(i,adj,nodes,edges,visited);
                if(edges/2 == (nodes*(nodes-1))/2){
                    ans++;
                }
            }
        }

        return ans;
    }
};
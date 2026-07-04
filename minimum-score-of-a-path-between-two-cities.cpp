class Solution {
public:
    void dfs(int node, unordered_map<int,vector<pair<int,int>>>& graph, vector<bool>&visi, int& ans){
        visi[node] = true;
        for(auto ngbr: graph[node]){
            int v = ngbr.first;
            int wt = ngbr.second;
            ans = min(ans,wt);
            if(!visi[v]){
                dfs(v, graph, visi, ans);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto road: roads){
            int u = road[0];
            int v = road[1];
            int dist = road[2];
            graph[u].push_back({v,dist});
            graph[v].push_back({u,dist});
        }
        vector<bool>visi(n,false);
        dfs(1,graph,visi,ans);

        return ans;
    }
};
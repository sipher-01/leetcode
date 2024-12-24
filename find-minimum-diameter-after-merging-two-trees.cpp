class Solution {
public:
    pair<int,int> bfs(unordered_map<int,vector<int>>&adj, int source){
        int dist = 0;
        unordered_map<int,bool>visi;
        queue<pair<int,int>>q;
        q.push({source,0});
        int node;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            visi[it.first] = true;
            node = it.first;
            dist = it.second;
            for(auto neighbor: adj[it.first]){
                if(visi[neighbor]==false)q.push({neighbor,it.second+1});
            }
        }
        return {node,dist};
    }
    int diameter(vector<vector<int>>& edges){
        int n = edges.size();
        unordered_map<int,vector<int>>adj;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        auto [farthest,dist] = bfs(adj,0);

        auto [node,dia] = bfs(adj,farthest);

        return dia;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
       int d1 = diameter(edges1);
       int d2 = diameter(edges2);
       int res = (d1+1)/2 + (d2+1)/2 + 1;
       return max({d1,d2,res});
    }
};
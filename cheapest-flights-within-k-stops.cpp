class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>cost(n,INT_MAX);
        cost[src]=0;
        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int edgeCost = q.front().second.second;
            q.pop();
            if(stops > k)continue;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjCost = it.second;
                if(edgeCost + adjCost < cost[adjNode]){
                    cost[adjNode] = edgeCost + adjCost;
                    q.push({stops+1,{adjNode,cost[adjNode]}});
                }
            }
        }
        if(cost[dst]!=INT_MAX)return cost[dst];
        return -1;
        
    }
};
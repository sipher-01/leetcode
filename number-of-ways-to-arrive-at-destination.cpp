class Solution {
public:
int mod = (int)1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,
        greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LONG_MAX);
        dist[0] = 0;
        vector<long long>ways(n,0);
        ways[0] = 1;
        while(!pq.empty()){
            long long edgeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(edgeDist>dist[node])continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjEdgeDist = it.second;
                if((long long)adjEdgeDist + edgeDist < dist[adjNode]){
                    dist[adjNode] = edgeDist + adjEdgeDist;
                    ways[adjNode] = ways[node]%mod;
                    pq.push({dist[adjNode],adjNode});
                }
                else if((long long)adjEdgeDist + edgeDist == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>p(n,0.0);
        p[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();
            if(node == end_node)return p[node];
            for(auto it : adj[node]){
                int adjNode = it.first;
                double edgeProb = it.second;
                if(prob * edgeProb > p[adjNode]){
                    p[adjNode] = prob*edgeProb;
                    pq.push({p[adjNode],adjNode});
                }
            }
        }
        return 0;

    }
};
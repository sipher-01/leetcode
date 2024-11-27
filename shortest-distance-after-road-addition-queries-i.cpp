class Solution {
public:
    // int dijkstra (vector<int> adj[], int n){
    //     queue<pair<int,int>>q;
    //     q.push({0,0});

    //     while(!q.empty()){
    //         auto node = q.front();
    //         int val = node.first;
    //         int len = node.second;
    //         q.pop();
    //         if(val == n-1)return len;
    //         for(auto it: adj[val]){
    //             q.push({it,len+1});
    //         }
    //     }
    //     return -1;
    // }
 int bfs(vector<int> adj[], int n) {
        vector<bool> visited(n, false);
        queue<pair<int, int>> q; // {node, distance}
        q.push({0, 0});
        visited[0] = true;

        while (!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if (node == n - 1) return dist;

            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, dist + 1});
                }
            }
        }
        return -1; // If no path exists
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        
        vector<int>adj[n];
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for (auto& query : queries) {
            adj[query[0]].push_back(query[1]); // Add new edge from query
            ans.push_back(bfs(adj, n));        // Compute shortest distance
        }
        return ans;
    }
};
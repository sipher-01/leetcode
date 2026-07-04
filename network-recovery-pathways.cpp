class Solution {
    int n;
    using ll = long long;
public:
    bool dfs(int node, int mn, ll sum, vector<bool>& online, 
    unordered_map<int,vector<pair<int,int>>>& graph, long long k, int mid){
        if(sum > k){
            return false;
        }
        if(node == n-1){
            // ans = max(ans, mn);
            return true;
        }

        for(auto ngbr: graph[node]){
            int j = ngbr.first;
            int wt = ngbr.second;
            if(online[j]==false || wt<mid)continue;
            int temp = min(mn, wt);
            if(dfs(j,temp,sum+wt,online,graph,k,mid)){
                return true;
            }
        }
        return false;
    }

    bool find(int limit, unordered_map<int, vector<pair<int,int>>>& adj,
              vector<bool>& online, vector<int>& topoSort, long long k){

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        for(int node : topoSort){
            if(dist[node] == LLONG_MAX) continue;

            for(auto &nxt : adj[node]){
                int nxtNode = nxt.first;
                int cst = nxt.second;

                if(cst < limit) continue;

                if(nxtNode != n-1 && !online[nxtNode]) continue;

                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst);
            }
        }

        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        unordered_map<int,vector<pair<int,int>>>graph;
        vector<int> indegree(n, 0);
        int mx = INT_MIN;
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            mx = max(mx,wt);
            indegree[v]++;
            graph[u].push_back({v,wt});
        }
        int mn = INT_MAX;
        int l = 0, r = mx;

        queue<int> q;
        vector<int> topoSort;

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topoSort.push_back(node);

            for(auto &ngbr : graph[node]){
                int nxtNode = ngbr.first;

                indegree[nxtNode]--;

                if(indegree[nxtNode] == 0){
                    q.push(nxtNode);
                }
            }
        }

        int ans = -1;
        while(l<=r){
            int mid = l + (r-l)/2;

            // if(dfs(0, mn, 0, online, graph, k, mid)){
            if(find(mid, graph, online, topoSort, k)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        
        return ans;
        
    }
};
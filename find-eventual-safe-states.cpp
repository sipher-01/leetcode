class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>indegree(n);
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                indegree[i]++;
                adj[it].push_back(i);
            }
        }
        vector<int>safe(n,0);
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
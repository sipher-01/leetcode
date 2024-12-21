class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>&values,int k, int&count,int cur,
    int parent)
    {
        int sum = values[cur];
        for(auto it: adj[cur]){
            if(it != parent){
                sum += dfs(adj,values,k,count,it,cur);
            }
        }
        sum %= k;
        if(sum==0)count++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int count = 0;
        dfs(adj,values,k,count,0,-1);
        return count;
    }
};
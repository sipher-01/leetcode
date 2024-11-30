class Solution {
public:
    void dfs(int node, vector<int>&path, unordered_map<int,vector<int>>&adj){

        while(!adj[node].empty()){
            int n = adj[node].back();
            adj[node].pop_back();
            dfs(n,path,adj);
        }
        path.push_back(node);
        return ;
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;

        for(auto it: pairs){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        int startNode = pairs[0][0];

        for(auto it: adj){
            if(outdegree[it.first] - indegree[it.first] == 1){
                startNode = it.first;
            }
        }
        // vector<int>visi
        vector<int>path;
        dfs(startNode,path,adj);
        reverse(path.begin(),path.end());
        vector<vector<int>>ans;
        for(int i=0; i<path.size()-1; i++){
            ans.push_back({path[i],path[i+1]});
        }
        return ans;
    }
};
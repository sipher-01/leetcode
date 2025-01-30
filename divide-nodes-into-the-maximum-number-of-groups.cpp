class Solution {
private:
    bool is_bipartite(int curNode,unordered_map<int,vector<int>>&adj,vector<int>&colors,int curColor){
        colors[curNode] = curColor;

        for(auto ngbr: adj[curNode]){
            if(colors[ngbr]==colors[curNode]){
                return false;
            }
            if(colors[ngbr]==-1){
                if(!is_bipartite(ngbr,adj,colors,1-curColor))return false;
            }
        }

        return true;
    }
    int bfs(unordered_map<int,vector<int>>&adj,int curNode,int n){
        queue<int>q;
        vector<bool>visi(n,false);
        visi[curNode] = true;
        int level = 0;
        q.push(curNode);
        while(!q.empty()){
            int s = q.size();
            for(int i=0; i<s; i++){
                auto it = q.front();
                q.pop();
                for(auto ngbr: adj[it]){
                    if(!visi[ngbr]){
                        q.push(ngbr);
                        visi[ngbr] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }
    int maxGroup(unordered_map<int,vector<int>>&adj,vector<int>&levels,vector<bool>&visi,int curNode){
        visi[curNode] = true;
        int maxCount = levels[curNode];
        for(auto ngbr: adj[curNode]){
            if(!visi[ngbr]){
                maxCount = max(maxCount,maxGroup(adj,levels,visi,ngbr));
            }
        }
        return maxCount;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;

        for(auto it: edges){
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colors(n,-1);
        for(int node=0; node<n; node++){
            if(colors[node]==-1){
                if(!is_bipartite(node,adj,colors,1)){
                    return -1;
                }
            }
        }

        vector<int>levels(n,0);
        for(int i=0; i<n; i++){
            levels[i] = bfs(adj,i,n);
        }

        int ans = 0;
        vector<bool>visi(n,false);
        for(int i=0; i<n; i++){
            if(!visi[i]){
                ans += maxGroup(adj,levels,visi,i);
            }
        }
    return ans;
    }
};
class DSU{
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=1; i<=n; i++)parent[i] = i;
    }

    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionByRank(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        if(parentX == parentY){
            return false;
        }
            if(rank[parentX] < rank[parentY]){
                parent[parentX] = parentY; 
            }
            else if(rank[parentX] > rank[parentY]){
                parent[parentY] = parentX;
            }
            else{
                parent[parentY] = parentX;
                rank[parentX]++;
            }
            return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int>ans(2,0);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            if(!dsu.unionByRank(u,v)){
                ans[0] = u;
                ans[1] = v;
            }
        }
        return ans;
    }
};
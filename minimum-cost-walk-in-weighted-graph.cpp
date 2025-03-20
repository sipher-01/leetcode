class Union_find{
vector<int>parent;
vector<int>size;
public:
    Union_find(int n){
        size = vector<int>(n,0);
        for(int i=0; i<n; i++)parent.push_back(i);
    }
    int find(int x){
        if(x==parent[x])return x;
        return parent[x] = find(parent[x]);
    }

    void unionBySize(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        if(parent_x == parent_y) return;
        if(size[parent_x]<size[parent_y]){
            parent[parent_x] = parent_y;
            size[parent_y] += size[parent_x];
        }
        else{
            parent[parent_y] = parent_x;
            size[parent_x] += size[parent_y];
        }
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        Union_find u(n);
        for(auto it: edges){
            int a = it[0];
            int b = it[1];
            int w = it[2];
            u.unionBySize(a,b);
        }

        unordered_map<int,int>component_weight;
        for(auto it: edges){
            int a = it[0];
            int w = it[2];
            int root = u.find(a);
            if(component_weight.find(root)==component_weight.end()){
                component_weight[root] = w;
            }
            else{
                component_weight[root] &= w;
            }
        }
        vector<int>ans;
        for(auto q: query){
            int rootS = u.find(q[0]);
            int rootE = u.find(q[1]);
            if(rootS!=rootE){
                ans.push_back(-1);
            }
            else{
                ans.push_back(component_weight[rootS]);
            }
        }
        return ans;
    }
};
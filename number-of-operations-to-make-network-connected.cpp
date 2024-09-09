class DisjointSet{
public:
    vector<int>parent,size;

    DisjointSet(int v){
        parent.resize(v);
        size.resize(v,1);
        for(int i=0; i<v; ++i){
            parent[i] = i;
        }
    }

    int findUparent(int x){
        if(x==parent[x])return x;
        return parent[x]=findUparent(parent[x]);
    }

    void unionBySize(int x,int y){
        int px = findUparent(x);
        int py = findUparent(y);
        if(px == py)return ;
        if(size[py]<size[px]){
            parent[py] = px;
            size[px] += size[py];
        }
        else{
            parent[px] = py;
            size[py] += size[px];
        }

    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findUparent(u) != ds.findUparent(v)){
                ds.unionBySize(u,v);
            }
            else{
                extra++;
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(ds.parent[i]==i)cnt++;
        }

        int ans=cnt-1;
        if(extra>=cnt-1)return ans;
        return -1;
    }
};
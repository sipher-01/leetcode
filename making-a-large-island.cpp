class Disjoint{
public:
    vector<int>size,parent;
    Disjoint(int v){
        size.resize(v+1,1);
        parent.resize(v+1);
        for(int i=0; i<=v; ++i){
            parent[i] = i;
        }
    }
    int findUparent(int x){
        if(parent[x]==x)return x;
        return parent[x] = findUparent(parent[x]);
    }
    
    void unionBySize(int a,int b){
        int pa = findUparent(a);
        int pb = findUparent(b);
        if(pa==pb)return ;
        if(size[pa]>size[pb]){
            parent[pb] = pa;
            size[pa] += size[pb];
        }
        else{
            parent[pa] = pb;
            size[pb] += size[pa];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint ds(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; ++j)
            {
                int r[] = {1,0,-1,0};
                int c[] = {0,1,0,-1};
                if(grid[i][j]==1){
                    for(int k=0; k<4; k++){
                        int adjr = i + r[k];
                        int adjc = j + c[k];
                        if(adjr>=0 && adjr<n && adjc>=0 && adjc<n &&
                         grid[adjr][adjc]==1){
                            int node1= i*n + j;
                            int node2 = adjr*n +adjc;
                            if(ds.findUparent(node1) != 
                            ds.findUparent(node2)){
                                ds.unionBySize(node1,node2);
                            }
                        }
                    }
                }
                else continue;
            }
        }

        int m =0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]==1)continue;
                int r[] = {1,0,-1,0};
                int c[] = {0,1,0,-1};
                set<int>comp;
                for(int k=0; k<4; k++){
                    int adjr = i + r[k];
                    int adjc = j + c[k];
                    if(adjr>=0 && adjr<n && adjc>=0 && adjc<n && grid[adjr][adjc]==1){
                        int node = adjr*n+adjc;
                        comp.insert(ds.findUparent(node));
                    }

                }     
                int maxsize=0;
                for(auto it:comp){
                    maxsize += ds.size[it];
                }
                m= max(maxsize+1,m);
            }
        }
        for(int i=0; i<n*n; i++){
            m = max(m,ds.size[ds.findUparent(i)]);
        }
        return m;
        
    }
};
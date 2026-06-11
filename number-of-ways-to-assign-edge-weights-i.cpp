class Solution {
    const int mod = 1e9+7;
public:
    int pow(int a, int b){
        int res = 1;
        while(b>0){
            if(b&1){
                res = (1LL*res*a)%mod;
            }
            a = (1LL*a*a) %mod;
            b >>=1;
        }
        return res;
    } 
    int dfs(int node, unordered_map<int,vector<int>>& tree, vector<int>& visi){
        visi[node] = true;
        int edge = 0;
        for(auto ngbr: tree[node]){
            if(visi[ngbr]==false) edge = max(edge, 1 + dfs(ngbr,tree,visi));
        }

        return edge;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>tree;
        set<int>st;

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            st.insert(u);
            st.insert(v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int n = st.size();
        vector<int>visi(n+1,false);



        int edge = dfs(1, tree, visi);
        cout<<edge<<endl;

        return pow(2,edge-1);

    }
};
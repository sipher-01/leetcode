class Disjoint{
public:
    vector<int>rank,parent;
    Disjoint(int v){
        rank.resize(v+1,0);
        parent.resize(v+1);
        for(int i=0; i<=v; ++i){
            parent[i] = i;
        }
    }
    int findUparent(int x){
        if(parent[x]==x)return x;
        return parent[x] = findUparent(parent[x]);
    }
    
    void unionByRank(int a,int b){
        int pa = findUparent(a);
        int pb = findUparent(b);
        if(pa==pb)return ;
        if(rank[pa]>rank[pb]){
            parent[pb] = pa;
        }
        else if(rank[pa]<rank[pb]){
            parent[pa] = pb;
        }
        else{
            parent[pa] = pb;
            rank[pb]++;
        }
    }
};
class Solution {
public:
    void dfs(int ind, vector<vector<int>>& stones, vector<bool>& visi, int n){
        visi[ind]=true;
        for(int i=0; i<n; i++){
            if(!visi[i]){
                if(stones[i][0] == stones[ind][0])dfs(i,stones,visi,n);
                if(stones[i][1] == stones[ind][1])dfs(i,stones,visi,n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        // vector<bool>visi(n);
        // int cnt = 0;
        // for(int i=0; i<n; i++){
        //     if(!visi[i]){
        //         dfs(i,stones,visi,n);
        //         cnt++;
        //     }
        // }
        // return n-cnt;
        int maxrow = 0;
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        Disjoint ds(maxrow+maxcol+1);
        unordered_map<int,int>mp;
        for(auto it: stones){
            int a = it[0];
            int b = it[1]+maxrow+1;
            ds.unionByRank(a,b);
            mp[a]=1;
            mp[b]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findUparent(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};
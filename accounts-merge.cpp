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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string,int>mailNode(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mailNode.find(accounts[i][j])==mailNode.end()){
                    mailNode[accounts[i][j]] = i;
                }
                else{
                    ds.unionByRank(i,mailNode[accounts[i][j]]);
                }
            }
        }

        vector<string>ans[n];
        for(auto it: mailNode){
            string mail = it.first;
            int node = ds.findUparent(it.second);
            ans[node].push_back(mail);
        }
        vector<vector<string>>res;
        for(int i=0; i<n; i++){
            if(ans[i].size()==0)continue;
            vector<string>temp;
            sort(ans[i].begin(),ans[i].end());
            temp.push_back(accounts[i][0]);
            for(auto it: ans[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};
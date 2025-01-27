class Solution {
public:
    void dfs(int i,unordered_map<int,vector<int>>&adj,vector<bool>&visi,set<int>&st){
        visi[i] = true;

        for(auto it: adj[i]){
            if(!visi[it]){
                st.insert(it);
                dfs(it,adj,visi,st);
            }
        }
        return ;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        unordered_map<int,set<int>>pre;
        for(int i=0; i<numCourses; i++){
            vector<bool>visi(numCourses,false);
            set<int>st;
            dfs(i,adj,visi,st);
            pre[i] = st;
        }
        vector<bool>ans;
        for(auto q: queries){
            int pq = q[0];
            int ele = q[1];
            if(pre[ele].count(pq)){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
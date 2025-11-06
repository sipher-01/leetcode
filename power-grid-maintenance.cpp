
using graph = vector<vector<int>>;
using pq = priority_queue<int,vector<int>,greater<int>>;


class Solution {
public:

    void dfs(int s, int id,graph&g, set<int>&online,unordered_map<int,int>&grid_ids,
    vector<pq>&power_grids){
        if (online.find(s)!=online.end()){
            return;
        }
        online.insert(s);
        grid_ids[s] = id;
        power_grids[id].push(s);
        for(auto ngbr : g[s]){
            if(online.find(ngbr)==online.end()){
                dfs(ngbr,id,g,online,grid_ids,power_grids);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        graph g(c+1);
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<pq>power_grids(c+1);
        set<int>online;
        unordered_map<int,int>grid_ids;

        for(int i=1; i<=c; i++){
            dfs(i,i,g,online,grid_ids,power_grids);
        }
        vector<int>ans;
        for(auto it: queries){
            int query = it[0];
            int station = it[1];
            if(query==1){
                if(online.find(station)!=online.end()){
                    ans.push_back(station);
                    continue;
                }
                int id = grid_ids[station];
                auto& power_grid = power_grids[id];
                while(!power_grid.empty() && (online.find(power_grid.top())==online.end())){
                    power_grid.pop();
                }
                if(!power_grid.empty()){
                    ans.push_back(power_grid.top());
                }
                else{
                    ans.push_back(-1);
                }
            }
            else{
                online.erase(station);
            }
        }

        return ans;
    }
};
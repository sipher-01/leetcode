// #define p pair<int,pair<int,int>>
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>mp;
        using p = pair<int,pair<int,int>>;
        int k = queries.size();
        for(int i=0; i<k; i++){
            mp.push_back({queries[i],i});
        }
        int n = grid.size();
        int m = grid[0].size();
        sort(begin(mp),end(mp));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>ans(k);
        pq.push({grid[0][0],{0,0}});
        visited[0][0] = true;
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(auto it: mp){
            while(!pq.empty() && pq.top().first < it.first){
                auto node = pq.top();
                pq.pop();
                int val = node.first;
                int row = node.second.first;
                int col = node.second.second;
                count++;
                for(int i=0; i<4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc <m && !visited[nr][nc]){
                        pq.push({grid[nr][nc],{nr,nc}});
                        visited[nr][nc] = true;
                    }
                }
            }
            ans[it.second] = count;
        }

        return ans;
    }
};
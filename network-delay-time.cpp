class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        while(!pq.empty()){
            int nTime = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjTime = it.second;
                if(adjTime + nTime < time[adjNode]){
                    time[adjNode] = adjTime + nTime;
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int ans = 0; 
        for(int i=1; i<time.size(); i++){
            if(time[i] == INT_MAX )return -1;
            ans = max(ans,time[i]);
        }
        return ans;

    }
};
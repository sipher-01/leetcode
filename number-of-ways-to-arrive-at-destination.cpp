
#define p pair<long long,int>
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<p, vector<p>, greater<p>>pq;
        pq.push({0,0});
        vector<long long>res(n,LLONG_MAX);
        vector<long long>count(n,0);
        res[0] = 0;
        count[0] = 1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long curTime = it.first;
            int node = it.second; 
            for(auto ngbr: adj[node]){
                int nbrNode = ngbr.first;
                int time = ngbr.second;
                if(curTime + time < res[nbrNode]){
                    res[nbrNode] = curTime + time;
                    pq.push({res[nbrNode],nbrNode});
                    count[nbrNode] = count[node];
                }
                else if(curTime + time == res[nbrNode]){
                    count[nbrNode] = (count[nbrNode] + count[node])%mod;
                }
            }
        }

        return count[n-1]%mod; 
    }
};
class Solution {
public:
    int bfs(int i, vector<int>adj[], vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push({i,0});
        int len = 0;
        while(!q.empty()){
            auto [node,dist] = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(!visited[it]){
                    visited[it] = true;
                    q.push({it,dist+1});
                    len = max(len,dist+1);
                }
            }
        }
        return len;
    }

    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int>adj[n];

        for(int i=0; i<n; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        vector<bool>visi(n,false);
        int maxEmp = 0;
        int happyCouple = 0;
        for(int i=0; i<n; i++){
            if(!visi[i]){
                unordered_map<int,int>mp;
                int currNode  = i;
                int currCount = 0;
                while(!visi[currNode]){
                    visi[currNode] = true;
                    mp[currNode] = currCount;

                    int neigh = favorite[currNode];
                    currCount +=1;
                    if(mp.count(neigh)){
                        int cycleLength = currCount -  mp[neigh];
                        maxEmp = max(maxEmp,cycleLength);
                        if(cycleLength == 2){
                            vector<bool>visited(n,false);
                            visited[currNode] = true;
                            visited[neigh] = true;
                            happyCouple += 2 + bfs(currNode,adj,visited) + 
                            bfs(neigh,adj,visited);
                        }
                        break;
                    }
                    currNode = neigh;
                }

            }
        }
        return max(happyCouple,maxEmp);
    }
};
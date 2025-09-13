class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        vector<int>prefix(n,0);
        unordered_map<int,int>map;
        queue<pair<int,int>>q;
        int ans = 0;
        for (int i=0; i<n; i++){
            int day = i+1;
            int type = arrivals[i];
            while (!q.empty() && q.front().first < day-w+1){
                map[q.front().second]--;
                if(map[q.front().second]==0){
                    map.erase(q.front().second);
                }
                q.pop();
            }
            if(map[type]>=m){
                ans++;
            }
            else{
            map[type]++;
            q.push({day,arrivals[i]});   
            }
        }
        return ans;
        
    }
};
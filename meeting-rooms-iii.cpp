#define ll long long
#define p pair<ll,int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int,vector<int>,greater<int>>free_rooms;
        priority_queue<p, vector<p>, greater<p>>end_times;
        vector<int>rooms(n,0);
        sort(meetings.begin(),meetings.end());
        for(int i=0; i<n; i++){
            free_rooms.push(i);
        }
        for(auto &it: meetings){
            ll m_start = it[0];
            ll m_end = it[1];
            ll delay = m_end - m_start;
            while(!end_times.empty() && end_times.top().first <= m_start){
                int id = end_times.top().second;
                free_rooms.push(id);
                end_times.pop();
            }

            if(free_rooms.empty()){
                auto [end_time,id] = end_times.top();
                end_times.pop();
                end_times.push({end_time + delay,id});
                rooms[id]++;
            }
            else{
                int id = free_rooms.top();
                free_rooms.pop();
                end_times.push({m_end,id});
                rooms[id]++;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            // cout<<i<<rooms[i]<<endl;
            if(rooms[i]>rooms[ans]){
                ans = i;
            }
        }
        return ans;
    }
};
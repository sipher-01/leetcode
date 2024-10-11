class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        int arrival_target = times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<int,vector<int>,
        greater<int>>free_chair;
        for(int i=0; i<n; i++){
            free_chair.push(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>occupied_chair;
        for(auto it: times){
            int arrival = it[0];
            int depart = it[1];
            while (!occupied_chair.empty() && occupied_chair.top().first <= arrival) {
                int chair_no = occupied_chair.top().second;
                occupied_chair.pop();
                free_chair.push(chair_no); // Mark chair as free
            }
                int num = free_chair.top();
                occupied_chair.push({depart,num});
                free_chair.pop(); 
            if(arrival == arrival_target){
                return num;
            }
        }
        return -1;
    }
};
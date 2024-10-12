class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort (intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &interval: intervals){
            int arrival = interval[0];
            int depart = interval[1];
            if(!pq.empty() && pq.top()<arrival){
                pq.pop();
            }
            pq.push(depart);
        }
        return pq.size();
    }
};
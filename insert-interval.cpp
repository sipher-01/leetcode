class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int n = intervals.size();
        int cur = 0;
        while(cur<n && intervals[cur][1]<newInterval[0]){
            ans.push_back(intervals[cur]);
            cur++;
        }
        if(cur==n){
            ans.push_back(newInterval);
            return ans;
        }
        if(intervals[cur][0]>newInterval[1]){
            ans.push_back(newInterval);
        }
        else{
            int l = min(intervals[cur][0], newInterval[0]);
            int r = max(intervals[cur][1], newInterval[1]);
            cur++;
            while(cur<n && intervals[cur][0]<=r){
                r = max(r,intervals[cur++][1]);
            }
            ans.push_back({l,r});
        }
        while(cur<n){
            ans.push_back(intervals[cur++]);
        }
        return ans;
    }
};
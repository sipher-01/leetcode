class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        int n=intervals.size();
        while(j<n){
            if(intervals[i][1]<=intervals[j][0]){
                i = j;
                j++;
            }
            else if(intervals[i][1]<=intervals[j][1]){
                ans++;
                j++;
            }
            else if(intervals[i][1]>intervals[j][1]){
                ans++;
                i=j;
                j++;
            }
        }
        return ans;
    }
};
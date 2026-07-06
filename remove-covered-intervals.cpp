class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto a, auto b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int s = -1, e = -1;
        int cnt = 1;
        for(auto it: intervals){
            int start = it[0];
            int end = it[1];
            if(s==-1 && e==-1){
                s = start;
                e = end;
                continue;
            }
            if(s<=start && end<=e){
                continue;
            }
            else{
                s = start;
                e = end;
                cnt++;
            }
        }

        return cnt;
    }
};
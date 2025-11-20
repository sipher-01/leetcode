class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        auto func = [&](auto &a, auto &b){
            if(a[1]==b[1])return a[0]>b[0];
            return a[1]<b[1];
        };
        sort(intervals.begin(),intervals.end(),func);
        int f=-1,s=-1;
        int res = 0;
        for(auto it: intervals){
            int l = it[0], r = it[1];
            if (l > s) {
                // interval has 0 of our points
                f = r - 1;
                s = r;
                res += 2;
            }
            else if (l > f) {
                // interval has exactly 1 point
                f = s;
                s = r;
                res += 1;
            }
        }
        return res;
    }
};
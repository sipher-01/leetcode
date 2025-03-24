class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int end = 0;
        int dayOff = 0;
        for(auto it: meetings){
            if(it[0]>end){
                dayOff += it[0] - end - 1; 
            }
            end = max(end,it[1]);
        }
        if(end<days){
            dayOff += days - end;
        }
        return dayOff;
    }
};
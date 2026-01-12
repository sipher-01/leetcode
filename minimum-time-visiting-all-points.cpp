class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        pair<int,int>coords;
        int i=0;
        for(auto p: points){
            if(i==0){
                coords = {p[0],p[1]};
            }
            else{
                int x = abs(p[0] - coords.first);
                int y = abs(p[1] - coords.second);
                int t = max(x,y);
                time += t;
                coords = {p[0], p[1]};
            }
            i++;
        }

        return time;
    }
};
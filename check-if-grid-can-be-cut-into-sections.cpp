class Solution {
public:
    bool solve(vector<vector<int>>& plane){
        sort(plane.begin(),plane.end());
        int cnt = -1;
        int end = 0;
        for(auto it: plane){
            if(it[0] >= end){
                cnt++;
            }
            end = max(end,it[1]);
        }
        return cnt>=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>x,y;
        for(auto it: rectangles){
            x.push_back({it[0],it[2]});
            y.push_back({it[1],it[3]});
        }
        bool ans;
        ans = solve(x);
        return ans || solve(y);
    }
};
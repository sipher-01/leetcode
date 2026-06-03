class Solution {
public:

    int solve(vector<int>&fs, vector<int>&fd, vector<int>&ss, vector<int>&sd){
        int ans = INT_MAX;
        int minL = INT_MAX;
        for(int i=0; i<fs.size(); i++){
            minL = min(minL, (fs[i]+fd[i]));
        }

        for(int i=0; i<ss.size(); i++){
            ans = min(ans,max(minL,ss[i]) + sd[i]);
        }
        return ans;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(solve(landStartTime,landDuration,waterStartTime,waterDuration),
        solve(waterStartTime,waterDuration,landStartTime,landDuration));
    }
};
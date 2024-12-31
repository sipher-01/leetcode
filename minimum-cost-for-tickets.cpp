class Solution {
    int dp[1000][1000];
public:
    int solve(int i, int limit, vector<int>& days, vector<int>& cost){
        if(i>=days.size())return 0;
        if(dp[i][limit]!=-1)return dp[i][limit];
        int one = INT_MAX,seven = INT_MAX,thirty = INT_MAX;
        int notTake = INT_MAX;
        if(days[i]>=limit){
            one = cost[0] + solve(i+1,days[i]+1,days,cost);
            seven = cost[1] + solve(i+1,days[i]+7,days,cost);
            thirty = cost[2] + solve(i+1,days[i]+30,days,cost);
        }
        else{
            notTake = solve(i+1,limit,days,cost);
        }

        return dp[i][limit] = min({one,seven,thirty,notTake});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days[0],days,costs);
    }
};
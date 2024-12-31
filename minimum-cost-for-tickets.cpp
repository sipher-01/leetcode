// class Solution {
//     int dp[1000][1000];
// public:
//     int solve(int i, int limit, vector<int>& days, vector<int>& cost){
//         if(i>=days.size())return 0;
//         if(dp[i][limit]!=-1)return dp[i][limit];
//         int one = INT_MAX,seven = INT_MAX,thirty = INT_MAX;
//         int notTake = INT_MAX;
//         if(days[i]>=limit){
//             one = cost[0] + solve(i+1,days[i]+1,days,cost);
//             seven = cost[1] + solve(i+1,days[i]+7,days,cost);
//             thirty = cost[2] + solve(i+1,days[i]+30,days,cost);
//         }
//         else{
//             notTake = solve(i+1,limit,days,cost);
//         }

//         return dp[i][limit] = min({one,seven,thirty,notTake});
//     }
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         memset(dp,-1,sizeof(dp));
//         return solve(0,days[0],days,costs);
//     }
// };
class Solution {
    int dp[366]; // dp[i] stores the minimum cost to cover days[i] to the end
public:
    int solve(int i, vector<int>& days, vector<int>& costs) {
        if (i >= days.size()) return 0; // Base case: no more days to cover
        if (dp[i] != -1) return dp[i]; // Memoization check

        // Option 1: Buy a 1-day pass
        int oneDayPass = costs[0] + solve(i + 1, days, costs);

        // Option 2: Buy a 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) j++; // Find the next day outside the 7-day range
        int sevenDayPass = costs[1] + solve(j, days, costs);

        // Option 3: Buy a 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) j++; // Find the next day outside the 30-day range
        int thirtyDayPass = costs[2] + solve(j, days, costs);

        // Take the minimum of all three options
        return dp[i] = min({oneDayPass, sevenDayPass, thirtyDayPass});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
        return solve(0, days, costs); // Start from the first day
    }
};

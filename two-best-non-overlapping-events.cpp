class Solution {
public:
    int solve(int i, vector<vector<int>>& events,int count,vector<vector<int>>&dp){
        if(count==2 || i>=events.size())return 0;
        if(dp[i][count]!=-1)return dp[i][count];
        int nextInd = bs(events,events[i][1]);
        int take = events[i][2] + solve(nextInd,events,count+1,dp);
        int notTake = solve(i+1,events,count,dp);

        return dp[i][count]=max(notTake,take); 

    }
    int bs(vector<vector<int>>& events,int x){
        int l =0;
        int n = events.size();
        int r = n-1;
        int res;
        while(l<=r){
            int mid = (l+r)/2;
            if(events[mid][0]<=x){
                l = mid+1;
            }
            else{
                res = mid;
                r = mid-1;
            }
        }

        return res;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        vector<vector<int>>dp(100001,vector<int>(3,-1));
        return solve(0,events,0,dp);

    }
};
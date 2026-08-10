class Solution {
    vector<int>dp;
    int l;
public:
    bool solve(int ind){
        if(ind==0){
            return false;
        }
        if(dp[ind]!=-1)return dp[ind];
        for(int i=1; i*i<=ind; i++){

            if(solve(ind-(i*i))==false)return dp[ind] = true;
            
        }
        return dp[ind] = false;
    }
    bool winnerSquareGame(int n) {
        // for(int i=0; i<=n; i++){
        //     mp[i]=1;
        // }
        dp.assign(n+1,-1);
        return solve(n);
    }
};
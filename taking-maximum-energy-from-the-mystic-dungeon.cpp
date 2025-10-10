class Solution {
public:

    int f(int i, vector<int>&energy, int k,vector<int>&dp){
        if(i>=energy.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        // if(i==energy.size()-1){
        //     return energy[i];
        // }
        return dp[i] = energy[i] + f(i+k,energy,k,dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int>dp(n,-1);
        for(int i=0; i<n; i++){
            ans =max(ans,f(i,energy,k,dp));
        }
        return ans;
    }
};
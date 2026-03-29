class Solution {
    const int mod = 1e9+7;
public:
    int countArrays(vector<int>& digitSum) {
        int n = digitSum.size();

        vector<int>count(5001,0);

        for(int i=0; i<5001; i++){
            int num = i;
            while(num>0){
                count[i] += num%10;
                num /= 10;
            }
        }

        vector<int>dp(5001,0);
        dp[0]=1;
        for(int i=0; i<n; i++){
            vector<int>t(5001);
            int pref = 0;
            for(int j=0; j<5001; j++){
                pref = (pref + dp[j]) %mod;
                if(count[j]!=digitSum[i])continue;
                t[j] = pref;
            }
            dp = t;
        }

        int ans = 0;
        for(int i=0; i<5001; i++){
            ans = (ans + dp[i])%mod;
        }

        return ans;
    }
};
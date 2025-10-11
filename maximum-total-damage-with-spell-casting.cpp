using ll = long long;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>mp;
        for(auto it:power){
            mp[it]++;
        }
        vector<pair<ll,ll>>f;
        f.push_back({-1e8,0});
        for(auto it: mp){
            f.push_back(it);
        }
        ll n = f.size();
        vector<ll>dp(n+1,0);
        ll mx = 0;

        for(int i=1,j=1; i<n; i++){
            // int j=1; 
            while(j<i && f[j].first < f[i].first-2){
                mx = max(mx,dp[j]);
                j++;
            }
            dp[i] = mx + 1LL * f[i].first * f[i].second;
        }

        ll ans = 0;

        for(int i=0; i<n; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
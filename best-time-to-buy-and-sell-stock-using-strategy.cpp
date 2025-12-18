class Solution {
public:
using ll = long long;
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        ll n = prices.size();
        vector<ll> profit(n);
        ll total = 0;
        for(ll i=0; i<n; i++){
            profit[i] = strategy[i] * prices[i];
            total += profit[i];
        }

        ll originalP = 0;
        ll modifiedP = 0;
        ll gain = 0;

        ll i=0,j=0;
        while(j<n){
            originalP += profit[j];
            if(j-i+1>k/2)modifiedP += prices[j];
            if(j-i+1>k){
                originalP -= profit[i];
                modifiedP -= prices[i+k/2];
                i++;
            }
            if(j-i+1 == k){
                gain = max(gain, modifiedP - originalP);
            }
            j++;
        }
        return gain+total;
    }
};
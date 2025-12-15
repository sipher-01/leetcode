using ll = long long;
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 1;
        int n = prices.size();
        int l = 0;
        for(int r=1; r<n; r++){
            if(prices[r-1] != prices[r] + 1){
                l = r;
            }
            ans += (r - l + 1); 
        }
        return ans;
    }
};
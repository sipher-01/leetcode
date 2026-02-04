class Solution {
public:
using ll = long long;
    long long maxSumTrionic(vector<int>& nums) {
        ll inf = -1e17;
        ll ans = -1e18;
        ll prev = nums[0];
        ll a = inf;
        ll b = inf;
        ll c = inf;

        for(int i=1; i<nums.size(); i++){
            ll n_a = inf;
            ll n_b = inf;
            ll n_c = inf;
            ll cur = nums[i];
            if(prev<cur){
                n_a = max(a,prev) + cur;
                n_c = max(c,b) + cur;
            }else if(cur<prev){
                n_b = max(b,a) + cur;
            }
            a = n_a;
            b = n_b;
            c = n_c;
            ans = max(ans,c);
            prev = cur;
        }
        return ans;
    }
};
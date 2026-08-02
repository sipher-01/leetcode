class Solution {
    using ll = long long;
public:
    ll gcd(ll a, ll b){
        if(b>a)return gcd(b,a);

        if(b==0)return a;

        return gcd(b,a%b);
    }
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        if(n<2)return 0;
        ll ans = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                ll num = 1ll*nums[i]*nums[j];
                ll g = gcd(nums[i],nums[j]);
                ll den = g*g;
                ll str = 0;
                if(den>0) str = num / den;
                ans = max(ans, str);
            }
        }

        return ans;
    }
};
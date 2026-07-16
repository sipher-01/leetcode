class Solution {
    using ll = long long;
public:
    ll gcd(ll a, ll b){
        if(b>a)return gcd(b,a);

        if(b==0)return a;

        return gcd(b,a%b);
    }


    long long gcdSum(vector<int>& nums) {
        ll ans = 0;

        int mx = 1;
        int n = nums.size();

        vector<int>pref;

        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            pref.push_back(gcd(mx,nums[i]));
        }

        sort(pref.begin(),pref.end());
        int l = 0, r = n-1;
        while(l<r){
            ans += gcd(pref[l++],pref[r--]);
        }

        return ans;
    }
};
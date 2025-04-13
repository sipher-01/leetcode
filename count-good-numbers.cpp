class Solution {
public:
using ll = long long;
ll mod = 1e9+7;
    ll pow(ll a, ll exp){
        ll res = 1;
        while(exp>0){
            if(exp%2!=0){
                res = (res * a)%mod;
            }
                a = (a*a)%mod;
                exp /= 2;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        ll ans = 1;
        ll total_odd = n/2;
        ll total_even = n%2==0?n/2:n/2+1;
        ans = (ans * pow(5,total_even))%mod;
        ans = (ans * pow(4,total_odd))%mod;
        return ans;
    }
};
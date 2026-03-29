class Solution {
    const int mod = 1e9+7;
    using ll = long long;
public:

    int power(int a, int b){
        int res = 1;

        while(b>0){
            if(b&1){
                res = (1LL * res * a)%mod;
            }
            a = (1LL *a*a)%mod;
            b /= 2;
        }

        return res%mod;
    }
    int inv(int a){
        return power(a,mod-2);
    }
    int countVisiblePeople(int n, int pos, int k) {
        ll ans = 2;

        for(int i=1; i<=k; i++){
            ans = (1LL*ans*(n-1-(i-1)))%mod;
            ans = (1LL*ans*inv(i))%mod;
        }

        return ans;
    }
};
class Solution {
    using ll = long long;
public:
    ll sqr(ll a){
        ll i = 1;
        while(i*i < a){
            i++;
        }
        return i;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
            sort(workerTimes.begin(),workerTimes.end());
            int n = workerTimes.size();
            ll l = 1 ;
            ll r = (ll)workerTimes[n-1]*mountainHeight*(mountainHeight+1)/2;

            ll ans = 0;
            auto check = [&](ll &time){
                ll height = 0;
                for(int i=0; i<n; i++){
                    double det = 1.0 + ((8.0*time) / workerTimes[i]);
                    ll val =  (sqrtl(det) - 1)/2;
                    height += val;
                    if(height >= mountainHeight)return true;
                }
                return false;
            };
            while(l<=r){
                ll time = (l + r) / 2;
                if(check(time)){
                    ans = time;
                    r = time - 1;
                }
                else{
                    l = time + 1;
                }
            }

            return ans;
    }
};
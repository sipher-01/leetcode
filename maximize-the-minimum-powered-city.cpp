using ll = long long;

class Solution {
public:


    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        ll L = *min_element(stations.begin(),stations.end());
        ll R = accumulate(stations.begin(),stations.end(),0LL) + k;
        ll ans  = 0;
        vector<ll>cnt(n+1);
        for(int i=0; i<n; i++){
            int left = max(0,i-r);
            int right = min(n,i+r+1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](ll x)->bool{
            vector<ll>diff = cnt;
            ll sum = 0;
            ll rem = k;

            for(int i=0; i<n; i++){
                sum += diff[i];
                if(sum<x){
                    ll add = x - sum;
                    if(rem<add){
                        return false;
                    }
                    rem -= add;
                    int end = min(n,i+2*r+1);
                    diff[end] -= add;
                    sum += add;  
                }
            }
            return true;
        };
        while(L<=R){
            ll mid = (L + R)/2;
            if(check(mid)){
                ans = max(ans,mid);
                L = mid+1;
            }
            else{
                R = mid-1;
            }
        }

        return ans;
    }
};
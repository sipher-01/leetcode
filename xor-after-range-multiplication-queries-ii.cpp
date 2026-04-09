#define  ll long long

class Solution {
    const int mod = 1e9+7;
public:

    int power(ll a, ll b){
        ll res = 1;

        while(b>0){
            if(b&1){
                res = ( res*a)%mod;
            }
            a = (a*a)%mod;
            b /= 2;
        }

        return res%mod;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int t = sqrt(n);
        int ans = 0;
        vector<vector<vector<int>>>group(t);

        for(auto q: queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if(k<t){
                group[k].push_back({l,r,v});
            }
            else{
                for(int i=l; i<=r; i+=k){
                    nums[i] = (1LL * nums[i] * v)%mod;
                }
            }
        }

        vector<ll>diff(n+t,1);
        for(int k=1; k<t; k++){
            if(group[k].empty())continue;
            int s = group[k].size();
            fill(diff.begin(), diff.end(), 1);
            for(int i=0; i<s; i++){
                int l = group[k][i][0];
                int r = group[k][i][1];
                int v = group[k][i][2];
                int R = l + ((r -l)/k + 1)*k;
                diff[l] = ( diff[l] * v)%mod;
                diff[R] = ( diff[R] * power(v,mod-2))%mod;
            }

            for(int j=k; j<n; j++){
                diff[j] = (diff[j] * diff[j-k])%mod;
            }

            for(int i=0; i<n; i++){
                nums[i] = (1LL * nums[i] * diff[i])%mod;
            }
        }

        for(int i=0; i<n; i++){
            ans = (nums[i]^ans);
        }

        return ans;
    }
};
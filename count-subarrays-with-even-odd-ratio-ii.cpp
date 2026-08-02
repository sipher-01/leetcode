using ll = long long;
class FT{
    vector<ll>a;
    int n;
public:
    FT(int n):a(vector<ll>(n+1)),n(n){}
    void add(int ind, int val){

        for(int i=ind+1; i<=n; i+=(i&(-i))){
            a[i] += val;
        }
    }

    int sum(int ind){
        int i = ind+1;
        int ans = 0;
        while(i>0){
            ans += a[i];
            i -= (i&(-i));
        }
        return ans;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<int>temp(n);

        for(int i=0; i<n; i++)temp[i] = (nums[i]&1) ? a:-b;

        vector<ll>pref(n+1);
        for(int i=1; i<=n; i++){
            pref[i] = pref[i-1]+temp[i-1];
        }

        vector<ll>sPref = pref;
        sort(sPref.begin(),sPref.end());
        sPref.erase(unique(sPref.begin(),sPref.end()),sPref.end());

        FT bit(n+1);

        ll ans = 0;
        for(int i=0; i<=n; i++){
            ll val = pref[i];

            auto it = lower_bound(sPref.begin(),sPref.end(),val) - sPref.begin();

            ans += bit.sum(it);

            bit.add(it,1);
        }
        return ans;
    }
};
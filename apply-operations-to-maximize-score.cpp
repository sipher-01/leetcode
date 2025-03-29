#define ll long long
class Solution {
public:
    const int mod = 1e9+7;
    vector<int> sieve(int n){
        vector<bool>isPrime(n+1,true);
        vector<int>primes;
        isPrime[0] = false;
        isPrime[1] = false;

        for(int i=2; i*i<=n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=n; j+=i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2; i<=n; i++){
            if(isPrime[i])primes.push_back(i);
        }
        return primes;
    }
    void nG(vector<int>&a,vector<int>&b){
        stack<int>st;
        int n = a.size();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && a[st.top()]<=a[i]){
                st.pop();
            }
            b[i] = st.empty()?n:st.top();
            st.push(i);
        }
    }
    void pS(vector<int>&a,vector<int>&b){
        stack<int>st;
        int n = a.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && a[st.top()]<a[i]){
                st.pop();
            }
            b[i] = st.empty()?-1:st.top();
            st.push(i);
        }
    }
    static bool comp(pair<int,int>&a, pair<int,int>&b){
        return a.first > b.first;
    }

    ll power(ll a, ll b){
        ll val = 1;
        while(b>0){
            if(b % 2 == 1){  // If b is odd
            val = (val * a) % mod;
            }
            a = (a * a) % mod;  // Square the base
            b /= 2; 
        }
        return val;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScore(n);
        int x = *max_element(begin(nums),end(nums));
        vector<int> primes = sieve(x);
        for(int i=0; i<n; i++){
            int num = nums[i];
            int cnt = 0;
            for(auto it: primes){
                if(it*it>num){
                    break;
                }
                bool found = false;
                while (num % it == 0) {
                    num /= it;
                    found = true;
                }
                if (found) cnt++;
            }
            if(num>1)cnt++;
            primeScore[i] = cnt;
        }
        vector<int>nextGreater(n,n);
        nG(primeScore,nextGreater);
        vector<int>prevGreater(n,-1);
        pS(primeScore,prevGreater);
        vector<ll>subarray(n);
        for(int i=0; i<n; i++){
            subarray[i] = (ll)(nextGreater[i]-i)* (i-prevGreater[i]);
        }

        vector<pair<int,int>>ind;

        for(int i=0; i<n; i++){
            ind.push_back({nums[i],i});
        }

        sort(begin(ind),end(ind),greater<>());
        ll ans = 1;
        int idx = 0;
        while(k>0){
            auto [val,i] = ind[idx];
            ll op = min((ll)k,subarray[i]);
            ans  = (ans* power((ll)val,op)%mod)%mod;
            k = k - op;
            idx++;
        }
        return ans%mod;
    }
};
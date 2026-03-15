class Fancy {
    using ll = long long;
    vector<ll>a;
    ll mul = 1;
    ll add = 0;
    const int mod = 1e9+7;
public:
    Fancy() {
        
    }
    ll power(ll a, ll b){
        ll res = 1;
        while(b>0){
            if(b&1){
                res = (res*a)%mod;
            }
            a = (a*a)%mod;
            b = b/2;
        }
        return res%mod;
    }
    void append(int val) {
        ll num = ((val - add + mod)%mod * power(mul,mod-2)%mod)%mod;
        a.push_back(num);
    }
    
    void addAll(int inc) {
        add = (add + inc)%mod;
    }
    
    void multAll(int m) {
        mul = (mul * m)%mod;
        add = (add * m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx >= this->a.size()) return -1;
        return ((a[idx] * mul)%mod + add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
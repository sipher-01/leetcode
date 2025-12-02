class Solution {
public:
const int mod = 1e9+7;

    // int fact(int n){
    //     if(n<=1)return 1;
    //     return n*fact(n-1);
    // }
    // int comb(int n, int r){
    //     if(n<r)return 0;
    //     if(n==r)return 1;
    //     int num = fact(n)%mod;
    //     int den= (fact(r)*fact(n-r))%mod;
    //     num = num/den;
    //     return num%mod;
    // }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long,long long>mp;

        for(auto it : points){
            mp[it[1]]++;
        }
        long long ans = 0;
        long long sum = 0;
        for(auto &[_,p]: mp){
            long long edge = ((p*(p-1))/2)%mod ;
            ans += edge * sum;
            sum += edge;
        }
        return ans%mod;
    }
};
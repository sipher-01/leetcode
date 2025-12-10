class Solution {
public:
    const int mod = 1e9+7;

    int fact(int n){
        if(n==0 || n==1)return 1;
        return (fact(n-1)* 1LL * n)%mod;
    }
    int countPermutations(vector<int>& complexity) {
        int mn = complexity[0];
        int n = complexity.size();
        for(int i=1; i<n; i++){
            if(complexity[i]<=mn)return 0;
        }
        int ans = fact(n-1)%mod;
        return ans;
    }
};
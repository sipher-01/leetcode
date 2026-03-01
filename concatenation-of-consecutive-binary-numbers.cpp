class Solution {
    const int mod = 1e9+7;
public:
    int concatenatedBinary(int n) {
        
        long long ans = 0;
        int bits = 0;
        // string 
        string temp = "";
        for(int i=1; i<=n; i++){
            if((i&(i-1))==0){
                bits++;
            }
            ans = ((ans<<bits)%mod + i)%mod;
        }
        // ans = stoll(temp);
        ans%mod;
        return ans;
    }
};
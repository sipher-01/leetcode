class Solution {
public:
    const int  mod = 1e9+7;
    int numSub(string s) {
        int l =0, r = 0;
        long long ans = 0,count = 0;
        int one = 0, zero = 0;
        long long n = s.length();
        while(r<n){
            if(s[r]=='0'){
                zero++;
            }
            else{
                one++;
            }
            while(l<=r && zero>0){
                if(s[l]=='0'){
                    zero--;
                }
                else{
                    one--;
                }
                l++;
            }
            ans += r-l+1;
            r++;
        }
        // for(char c : s) {
        //     if(c == '1') {
        //         count++;           // extend the streak of ones
        //         ans += count;      // add all substrings ending here
        //     } else {
        //         count = 0;         // reset when you hit a zero
        //     }
        // }
        return ans%mod;
    }
};
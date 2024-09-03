class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        string temp;
        for(auto it : s){
            int a = it - 'a' + 1;
            temp += to_string(a);
        }
        while(k--){
            ans = 0;
            for(auto it: temp){
                int a = it-'0';
                ans += a;
            }
            temp = to_string(ans);
        }
        return ans;
    }
};
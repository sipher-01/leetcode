class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int cur = 1;
        int ans = 0;
        for(int i=1; i<s.length(); i++){
            if(s[i-1]!=s[i]){
                ans += min(prev,cur);
                prev = cur;
                cur = 1;
            }
            else{
                cur++;
            }
        }
        return ans + min(cur,prev);
    }
};
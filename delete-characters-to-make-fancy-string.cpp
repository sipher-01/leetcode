class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt = 0;
        char prev = '#';
        for(int i=0; i<s.length(); i++){
            if(prev!=s[i])cnt=1;
            else cnt++;
            if(cnt<=2){
                ans+=s[i];
            }
            prev = s[i];
        }
        return ans;
    }
};
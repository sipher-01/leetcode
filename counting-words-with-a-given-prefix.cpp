class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int l = pref.length();
        int ans = 0;
        for(auto it: words){
            if(it.substr(0,l) == pref)ans++;
        }
        return ans;
    }
};
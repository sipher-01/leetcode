class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() || s.size()<t.size())return "";
        int minLen = INT_MAX;
        int startInd = -1;
        int l=0, r=0;
        int cnt=0;
        vector<int> mp(128, 0); // Initialize character count array
        
        // Count characters in t
        for (char ch : t) {
            mp[ch]++;
        }
        while(r<s.size()){
              if (mp[s[r++]]-- > 0) {
                cnt++;
            }
            while(cnt == t.size()){
                if (r - l < minLen) {
                    startInd = l;
                    minLen = r - l ;
                }

                if (++mp[s[l++]] > 0) {
                    cnt--;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(startInd, minLen);
    }
};
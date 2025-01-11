class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length())return false;
        vector<int>freq(26,0);
        int n = s.length();

        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2!=0)cnt++;
        }
        if(cnt<=k)return true;
        return false;
    }
};
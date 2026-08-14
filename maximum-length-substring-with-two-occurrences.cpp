class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int n = s.length();
        int l = 0;

        unordered_map<char,int>mp;
        int ans = 0;

        for(int r=0; r<n; r++){
            mp[s[r]]++;
            while(!mp.empty() && mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};
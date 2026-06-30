class Solution {
public:
    int numberOfSubstrings(string s) {
        int l =0;
        unordered_map<char,int>mp;
        int n = s.length();

        int ans = 0;
        for(int r=0; r<n; r++){
            mp[s[r]]++;
            while(mp.size()>=3){
                ans += (n-r);
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
        }

        return ans;
    }
};
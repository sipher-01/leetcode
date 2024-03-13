class Solution {
public:
    int numberOfSubstrings(string s) {
            int n = s.size();
    map<char,int>mp;
    mp['a']=0;
    mp['b']=0;
    mp['c']=0;
    int l=0, r=0;
    int ans=0;
    while(r<n){
        mp[s[r]]++;
        while(mp['a']>0 && mp['b']>0 && mp['c']>0){
            ans+=n-r;
            mp[s[l]]--;
            l++;
        }
        r++;
    }
    return ans;
    }
};
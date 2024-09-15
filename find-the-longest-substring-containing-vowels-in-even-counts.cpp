class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>v;
        v[0]=-1;
        int maxi = 0;
        int mask = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i'||s[i]=='o'||s[i]=='u'){
                mask ^= 1<<(s[i]-'a');
            }
            if(v.find(mask)!=v.end()){
                maxi = max(maxi,i - v[mask]);
            }
            else{
                v[mask] = i;
            }
        }
        return maxi;

    }
};
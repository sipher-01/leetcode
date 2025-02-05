class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt =0;
        int l = s1.length();
        map<int,int>mp1;
        map<int,int>mp2;
        for(int i=0; i<s1.length(); i++){
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
            if(s1[i]==s2[i])cnt++;
        }
        if(mp1!=mp2)return false;
        if(l-2==cnt || cnt==l)return true;
        return false;
    }
};
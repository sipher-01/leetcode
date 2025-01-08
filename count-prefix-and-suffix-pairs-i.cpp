class Solution {
public:
    bool isp_s(string &s1, string &s2){
        if(s1.length()>s2.length())return false;
        int l = s1.length();
        int l2 = s2.length();
        if(s1 == s2.substr(0,l) && s1 == s2.substr(l2-l,l))return true;
        return false;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if( isp_s(words[i],words[j]))ans++;
            }
        }
        return ans;
    }
};
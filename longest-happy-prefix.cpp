class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        if(n==1)return "";
        int i=0;
        int j=1;
        vector<int>lcs(n,0);
        while(j<n){
            if(s[i]==s[j]){
                lcs[j] = i+1;
                i++,j++;
            }
            else{
                if(i==0)j++;
                else{
                    i = lcs[i-1];
                }
            }
        }
        int len = lcs[n-1];
        if(len==n || len==0)return "";
        string prefix = s.substr(0,len);
        return prefix;
    }
};
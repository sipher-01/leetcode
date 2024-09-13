class Solution {
public:
    int strStr(string haystack, string needle) {
        int startInd = -1;
        int n = haystack.size();
        int m = needle.size();
        if(m>n)return -1;
        int i=0, j=0;
        int cnt=0;
        while(i<n){
            if(haystack[i]==needle[j]){
                cnt++;
                if(cnt==1){
                    startInd = i;
                }
                if(cnt == m){
                    return startInd;
                }
                i++;
                j++;
            }
            else{
                i = i-cnt + 1;
                cnt=0;
                startInd = -1;
                j=0;
            }
        }
        return -1;
    }
};
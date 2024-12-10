class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        vector<vector<int>>mat(26,vector<int>(n+1,0));
        int length = 0;
        char prev=s[0];
        for(int i=0; i<n; i++){
            if(prev == s[i]){
                length++;
                mat[s[i]-'a'][length] += 1;
            }else{
                length = 1;
                mat[s[i]-'a'][length] += 1;
                prev = s[i];
            }
        }
        int res = 0;
        for(int row=0; row<26; row++){
            int cumSum = 0;
            for(int col=n; col>=1; col--){
                cumSum += mat[row][col];
                if(cumSum>=3){
                    res = max(res,col);
                    break;
                }
            }
        }
        return res==0?-1:res;
    }
};
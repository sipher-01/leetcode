class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i=0,j=0;
        int n = word1.length(), m = word2.length();
        bool check = true;
        while(i<n && j<m){
            if(check==true){
                ans += word1[i];
                i++;
                check = false;
            }
            else{
                ans += word2[j];
                j++;
                check = true;
            }
        }
        while(i<n){
                ans += word1[i];
                i++;
                check = false;
        }
        while(j<m){
                ans += word2[j];
                j++;
                check = true;
        }
        return ans;
    }
};
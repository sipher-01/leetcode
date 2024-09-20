class Solution {
public:
    string shortestPalindrome(string s) {
        string s1=s,s2;
        reverse(s1.begin(),s1.end());
        s2 = s + '#' + s1;
        int i = 0;
        int j = 1;
        vector<int>lps(s2.size(),0);
        while(j<s2.size()){

            if(s2[i]==s2[j]){
                    lps[j] = i+1;
                    i++;
                    j++;
            }
            else{
                if(i==0)j++;
                else{
                    i = lps[i-1];
                }
            }

        }
        int len = lps[s2.size()-1];
        string toAdd = s.substr(len);
        reverse(toAdd.begin(),toAdd.end());
        string ans = toAdd + s;
        return ans;
    }
};
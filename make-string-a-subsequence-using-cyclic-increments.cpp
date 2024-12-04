class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        vector<char>letters(26);
        for(char c='a'; c<='z'; c++){
            letters[c-'a']=c;
        }
        int i = 0, j = 0;
        while (i < str1.length() && j < str2.length()) {
            if (str1[i] == str2[j]) {
                j++;
            } else if (letters[((str1[i] - 'a') + 1) % 26] == str2[j]) {
                j++;
            }
            i++;
        }
        return j == str2.length();
    }
};
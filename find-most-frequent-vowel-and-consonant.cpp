class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel,consonant;

        for (char c: s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                vowel[c]++;
            }
            else{
                consonant[c]++;
            }
        }
        int v=0,c=0;

        for (auto it: vowel){
            v = max(v,it.second);
        }
        for (auto it: consonant){
            c = max(c,it.second);
        }

        return v+c;
    }
};
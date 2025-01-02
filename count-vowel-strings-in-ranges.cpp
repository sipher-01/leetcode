class Solution {
public:
    bool isTrue(string &s){
        int n = s.length();
        bool check1 = false , check2 = false;
        if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u')
        check1=true;

        if(s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u')
        check2=true;
        return check1 && check2;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>comp(n+1,0);
        // comp[0] = (isTrue(words[0])?1:0);
        for(int i=0; i<n; i++){
            comp[i+1]= comp[i] + (isTrue(words[i])?1:0);
        }
        vector<int>res;
        for(auto it: queries){
            int l = it[0], r = it[1];
            res.push_back(comp[r+1] - comp[l]);
        }
        return res;
    }
};
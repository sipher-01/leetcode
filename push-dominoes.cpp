class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = dominoes;
        s = 'L' + s + 'R';
        string res;
        int prev = 0;
        for(int i=1; i<s.size(); i++){
            if(s[i]=='.')continue;
            int span = i - prev - 1;

            if(prev>0){
                res += s[prev];
            }

            if(s[prev] == s[i]){
                res += string(span,s[prev]);
            }
            else if(s[prev]=='L' && s[i]=='R'){
                res += string(span,'.');
            }
            else{
                res += string(span/2,'R');
                res += string(span%2,'.');
                res += string(span/2,'L');
            }
            prev = i;
        }
        return res;
    }
};
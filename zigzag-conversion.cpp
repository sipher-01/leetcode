class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)return s;
        string res = "";
        for(int i=0; i<numRows; i++){
            int inc = 2*(numRows-1);
            for(int r=i; r<s.size(); r+=inc){
                res+=s[r];
                if(i>0 && i<numRows-1 && r+inc-2*i<s.size()){
                    res += s[r+inc-2*i];
                }
            }
        }
        return res;
    }
};
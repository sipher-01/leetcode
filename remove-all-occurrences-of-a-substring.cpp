class Solution {
public:
    string removeOccurrences(string s, string part) {
        string t = s;
        int l = part.length();
        while(t.find(part)!=string::npos){
            auto it = t.find(part);
            t.erase(it,l);
        }
        return t;
    }
};
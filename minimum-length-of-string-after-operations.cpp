class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(char t: s){
            mp[t]++;
        }
        int del = 0;
        for(auto it: mp){
            if(it.second%2==1){
                del += it.second - 1;
            }
            else{
                del += it.second - 2;
            }
        }
        return s.length()-del;
    }
};
class Solution {
public:
    int maximumLength(string s) {
        map<pair<char,int>,int>mp;

        for(int i=0; i<s.length(); i++){
            char cur =s[i];
            for(int j=i; j<s.length(); j++){
                if(cur == s[j]){
                    mp[{cur,j-i+1}]++;
                }else{
                    break;
                }
            }
        }
        int res = 0;
        for(auto it: mp){
            if(it.second>=3 && it.first.second>res){
                res = it.first.second;
            }
        }
        return res==0?-1:res;
    }
};
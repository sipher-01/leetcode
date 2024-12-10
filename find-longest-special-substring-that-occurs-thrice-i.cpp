class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>mp;

        for(int i=0; i<s.length(); i++){
            string cur ="";
            for(int j=i; j<s.length(); j++){
                if(cur.empty() || cur.back() == s[j]){
                    cur += s[j];
                    mp[cur]++;
                }else{
                    break;
                }
            }
        }
        int res = 0;
        for(auto it: mp){
            if(it.second>=3 && it.first.length()>res){
                res = it.first.length();
            }
        }
        return res==0?-1:res;
    }
};
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string>ans;
        for(auto s: words){
            for(auto s1: words){
                if(s != s1 && s.find(s1)!= string::npos){
                    ans.insert(s1);
                }
            }
        }
        vector<string>res(ans.begin(),ans.end());
        return res;
    }
};
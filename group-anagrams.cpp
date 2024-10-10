class Solution {
    map<string,vector<string>>mp;
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        if(strs.size()==0)return ans;
        for(auto it: strs){
            string temp = it;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(it);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
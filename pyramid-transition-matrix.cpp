class Solution {
public:
    unordered_map<string, bool>dp;
    bool solve(string curr, int idx, unordered_map<string,vector<char>>&mp, string above){
        if(curr.length()==1){
            return true;
        }
        string key = curr + "_" + to_string(idx) + "_ "+ above;
        if(dp.count(key)){
            return dp[key];
        }
        if(idx+1==curr.length()){
            return  dp[key] = solve(above,0,mp,"");
        }
        string temp = curr.substr(idx,2);
        if(mp.find(temp)==mp.end()){
            return false;
        }
        for(auto &it: mp[temp]){
            above.push_back(it);
            if(dp[key] = solve(curr,idx+1,mp,above))return true;
            above.pop_back();
        }

        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string,vector<char>>mp;
        for(auto it: allowed){
            string t = it.substr(0,2);
            mp[t].push_back(it[2]);
        }
        return solve(bottom, 0, mp, "");
    }
};
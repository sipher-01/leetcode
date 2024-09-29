class Solution {
private:
    void helper1(string &ans, vector<pair<int,int>>&freq){
        char c = ans[0];
        int cnt = 1;
        for(int i=1; i<ans.length(); i++){
            if(c==ans[i]){
                cnt++;
            }
            else{
                freq.push_back({cnt,c-'0'});
                cnt=1;
                c = ans[i];
            }
        }
        freq.push_back({cnt,c-'0'});
    }
    string helper2(vector<pair<int,int>>&freq){
        string res="";
        for(auto it: freq){
            res +=to_string(it.first);
            res +=to_string(it.second);
        }
        return res;
    }
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string ans = "1";
        for(int i=2; i<=n; i++){
            vector<pair<int,int>>freq;
            helper1(ans,freq);
            ans = helper2(freq);
        }
        return ans;
    }
};
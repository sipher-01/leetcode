class Solution {
public:
int ans=0;
    void solve(int i, string s, set<string>&st){
        if(i>=s.length()){
            ans = max(ans,(int)st.size());
            return;
        }
        string temp = "";
        for(int ind = i; ind<s.length(); ind++){
            temp = temp + s[ind];
            if(st.find(temp)==st.end()){
                st.insert(temp);
                solve(ind+1,s,st);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        set<string>st;
        solve(0,s,st);
        return ans;
    }
};
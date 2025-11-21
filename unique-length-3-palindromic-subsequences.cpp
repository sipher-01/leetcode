class Solution {
public:
    bool check(string& t){
        if(t[0]==t[2])return 1;
        return 0;
    }
    void solve(int i, string& s , string t, set<string>&st){
        if(i>s.length())return;
        if(t.length()==3 && check(t)){
            st.insert(t);
            return;
        }

        solve(i+1,s,t,st);
        solve(i+1,s,t+s[i],st);
    } 
    int countPalindromicSubsequence(string s) {
        // set<string>st;
        // solve(0,s,"",st);
        // return st.size();
        int n = s.length();
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i=0; i<n; i++){
            int val = s[i] - 'a';
            if(first[val]==-1){
                first[val] = i;
            }
            last[val] = i;
        }
        int ans = 0;
        for(int i=0; i<26; i++){
            unordered_set<char>st;
            for(int j=first[i]+1; j<last[i]; j++){
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
    }
};
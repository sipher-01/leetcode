class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.length()==0)return 0;
        stack<char>st;
        int open = 0, close = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push('(');
            }
            else {
                if(st.empty())close++;
                else st.pop();
            }
        }
        open = st.size();
        int ans = open+close;
        return ans;

    }
};
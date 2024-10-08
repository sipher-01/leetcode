class Solution {
public:
    int minSwaps(string s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='[')st.push(1);
            else {
                if(!st.empty())st.pop();
            }
        }
        return (st.size()+1)/2;
    }
};
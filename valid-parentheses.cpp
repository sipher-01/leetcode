class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int flag=0;
        for(char it: s){
            if(it=='(' || it=='[' || it=='{'){
                st.push(it);
            }
            else{
                if(!st.empty()){
                    if(st.top() =='(' && it==')')st.pop();
                    else if(st.top()=='[' && it==']')st.pop();
                    else if(st.top()=='{' && it=='}')st.pop();
                    else flag=1;
                }
                else flag = 1;
            }
        }
        return st.empty() && flag==0;
    }
};
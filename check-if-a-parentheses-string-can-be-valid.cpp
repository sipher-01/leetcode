class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>st1;
        stack<int>st2;
        int i=0;
        int n = s.length();
        if(n%2!=0)return false;
        for(int i=0; i<n; i++){
            if(locked[i] == '0')st2.push(i);
            else if(s[i] == '(')st1.push(i);
            else if(s[i]==')'){
                if(!st1.empty()){
                    st1.pop();
                }
                else if(!st2.empty()){
                    st2.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!st1.empty() && !st2.empty() && st1.top()<st2.top()){
            st1.pop();
            st2.pop();
        }
        return st1.empty();
    }
};
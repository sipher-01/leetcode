class Solution {
public:
    bool andExp(string s){
        int n = s.length(), j=0;
        string subs;
        int active = 0;
        while(j<n){
            if(active==0 && s[j]==','){
                if(parseBoolExpr(subs)==false)return false;
                subs = "";
                j++;
                continue;
            }
            if(s[j]=='(')active++;
            if(s[j]==')')active--;
            subs += s[j++];
        }
        if(parseBoolExpr(subs))return true;
        return false;
    }
    bool orExp(string s){
        int n = s.length(), j=0;
        string subs;
        int active = 0;
        while(j<n){
            if(active == 0 && s[j]==','){
                if(parseBoolExpr(subs))return true;
                subs= "";
                j++;
                continue;
            }
            if(s[j]=='(')active++;
            if(s[j]==')')active--;
            subs += s[j++];
        }
        if(parseBoolExpr(subs))return true;
        return false;
    }
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        if(n==1)return (expression[0]=='t');
        if(expression[0]=='!') return !parseBoolExpr(expression.substr(2,n-3));
        if(expression[0]=='|')return orExp(expression.substr(2,n-3));
        if(expression[0]=='&')return andExp(expression.substr(2,n-3));
        return false;
    }
};
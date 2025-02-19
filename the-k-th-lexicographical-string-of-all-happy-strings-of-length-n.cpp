class Solution {
public:
    bool check(char a, char b){
        return a!=b;
    }
    void solve(int i, int n, string temp,char prev,int &cnt, string&res, int k){
        if(cnt>=k)return;
        if(i==n){
            cnt++;
            if(cnt==k){
                res = temp;
            }
            return;
        }
        for(char c='a'; c<='c'; c++){
            if(check(c,prev)){
                solve(i+1,n,temp+c,c,cnt,res,k);
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        // vector<string>happy_strings;
        int cnt = 0;
        string res = "";
        for(char c='a'; c<='c'; c++){
            string temp(1,c);
            solve(1,n,temp,c,cnt,res,k);
            if(!res.empty())return res;
        }
        return "";
    }
};
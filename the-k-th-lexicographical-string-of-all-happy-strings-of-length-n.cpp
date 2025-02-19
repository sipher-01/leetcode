class Solution {
public:
    bool check(char a, char b){
        return a!=b;
    }
    void solve(int i, int n, string temp,char prev, vector<string>&hs){
        if(i==n){
            hs.push_back(temp);
            return;
        }
        for(char c='a'; c<='c'; c++){
            if(check(c,prev)){
                solve(i+1,n,temp+c,c,hs);
            }
        }
        return;
    }
    string getHappyString(int n, int k) {
        vector<string>happy_strings;
        for(char c='a'; c<='c'; c++){
            string temp(1,c);
            solve(1,n,temp,c,happy_strings);
        }
        if(happy_strings.size()<k)return "";
        return happy_strings[k-1];
    }
};
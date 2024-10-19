class Solution {
    char res;
public:
    string invert(string s){
        string temp;
        for(int i=0; i<s.size(); i++){
            if (s[i] == '0') temp += '1';
            else temp += '0';
        }
        return temp;
    }
    void solve(int i,int n, int k,string s){
        if((s.length()/2)>=k){
            res = s[k-1];
            return ;
        }
        if(i==n)return;
            string temp = invert(s);
            reverse(temp.begin(),temp.end());
            s = s + "1" + temp;
            solve(i+1,n,k,s);
    }
    char findKthBit(int n, int k) {
        string s = "0"; 
        solve(0,n,k,s);
        return res;
    }
};
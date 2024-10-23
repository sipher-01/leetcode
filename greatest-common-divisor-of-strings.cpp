class Solution {
public:
    int Gcd (int a, int b){
        if(b>a)return Gcd(b,a);
        if(b == 0)return a;
        return Gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2 + str1)return "";
        int n=str1.length(), m=str2.length();
        int gcd = Gcd(n,m);
        string ans = str1.substr(0,gcd);
        return ans;
    }
};
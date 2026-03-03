class Solution {
    vector<string>s = vector<string>(21,"0");
public:
    string invert(string &a){
        string temp = "";
        int i = a.length()-1;
        while(i>=0){
            if(a[i]=='1'){
                temp += '0';
            }else{
                temp += '1';
            }
            i--;
        }
        return temp;
    }
    void cal(){
        for(int i=2; i<=20; i++){
            string temp = s[i-1];
            string a = invert(s[i-1]);
            // reverse(a.begin(),a.end());
            temp += "1" + a;
            s[i] = temp;
        }
    }
    char findKthBit(int n, int k) {
        cal();
        return s[n][k-1];
    }
};
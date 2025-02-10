class Solution {
public:
    string clearDigits(string s) {
        string a;
        int n = s.length();
        vector<bool>mark(n,true);
        for(int i=0; i<n; i++){
            if(s[i]>='0' && s[i]<='9'){
                mark[i]=false;
                int j = i-1;
                while(j>=0){
                    if(s[j]>='a' && s[j]<='z' && mark[j]){
                        mark[j] = false;
                        break;
                    }
                    j--;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(mark[i]){
                a+=s[i];
            }
        }
        return a;
    }
};
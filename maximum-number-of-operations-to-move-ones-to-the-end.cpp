class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int op = 0;
        int ones = 0;

        // int l = 0;
        // while(s[l]!=1){
        //     l++;
        // }
        for(int r=0; r<n; r++){
            if(s[r]=='0'){
                op += ones;
            }
            while(s[r]=='0' && r<n){
                r++;
            }
            if(s[r]=='1'){
                ones++;
            }
        }

        return op;
    }
};
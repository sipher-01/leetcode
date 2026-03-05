class Solution {
public:
    int minOperations(string s) {
        int op1 = 0, op2 = 0;
        int n = s.length();
        char num = '0';
        for(int i=0; i<n; i++){
            if(i%2 && s[i]=='0'){
                op1++;
            }
            if(i%2==0 && s[i]=='1'){
                op1++;
            }
        }
        num = '1';
        for(int i=0; i<n; i++){
            if(i%2 && s[i]=='1'){
                op2++;
            }
            if(i%2==0 && s[i]=='0'){
                op2++;
            }
        }
        return min(op1,op2);
    }
};
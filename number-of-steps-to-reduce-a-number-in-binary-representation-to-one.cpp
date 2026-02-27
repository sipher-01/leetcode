class Solution {
public:
    int numSteps(string s) {
        int add = 0;
        int r = s.length()-1;
        int ans = 0;
        while(r>0){
            if(s[r]=='0'){
                if(add==1){
                    ans += 2;
                    add = 1;
                }
                else{
                    ans += 1;
                    // add = 0;
                }
            }
            else{
                if(add==1){
                    ans += 1;
                    add = 1;
                }
                else{
                    ans += 2;
                    add = 1;

                }
            }
            r--;
        }
        if(s[0]=='1'){
            if(add==1){
                ans += 1;
            }
            else{
                ans += 0;
            }
        }
        // else{
        //     if(add = 1){

        //     }
        // }
        return ans;
        
    }
};
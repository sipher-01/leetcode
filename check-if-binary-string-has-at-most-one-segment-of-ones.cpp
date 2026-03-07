class Solution {
public:
    bool checkOnesSegment(string s) {
        int one =0, zero = 0;

        for(char &c: s){
            if(c=='1'){
                if(one >0 && zero > 0)return false;
                one++;
            }
            else zero++;
        }
        return true;
    }
};
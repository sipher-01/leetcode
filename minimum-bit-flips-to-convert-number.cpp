class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = start^goal;
        int cnt = 0;
        while(res>0){
            int ones = res&1;
            if(ones==1)cnt++;
            res = res>>1;
        }
        return cnt;
    }
};
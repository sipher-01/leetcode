class Solution {
public:
    long long minEnd(int n, int x) {
        long long cnt = x;
        while(n>1){
                cnt = x | (cnt+1);
                n--;
        }
        return cnt;
    }
};
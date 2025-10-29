class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;

        for(int i=0; i<32; i++){
            int num = (1<<i);
            if(num>n){
                ans = num-1;
                return ans;
            }
        }
        return -1;
    }
};
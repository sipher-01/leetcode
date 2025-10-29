class Solution {
public:
    int smallestNumber(int n) {
        int ans = 0;

        for(int i=0; i<=10; i++){
            int num = (1<<i);
            if(num>n){
                ans = num-1;
                return ans;
            }
        }
        return -1;
    }
};
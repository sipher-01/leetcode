class Solution {
public:
    int binaryGap(int n) {
        int dist = 0;
        int prev = 1e9;
        for(int i=0; i<32; i++){
            if((n>>i)&1){
                dist = max(dist,i-prev);
                prev = i;
            }
        }
        return dist;
    }
};
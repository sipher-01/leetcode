class Solution {
public:
    int reverseBits(int n) {
        int num = 0;
        int l = 0, r = 31; 
        for(int i=0; i<16; i++){
            int bit_l = (n>>i & 1);
            int bit_r = (n>>(31-i) & 1);
            num |= bit_r<<i; 
            num |= bit_l<<(31-i);
        }
        return num;
    }
};
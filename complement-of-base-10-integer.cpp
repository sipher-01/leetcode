class Solution {
public:
    int bitwiseComplement(int n) {
        int ans = 0;
        int mx = 0;
        for(int i=0; i<32; i++){
            if((n>>i & 1)){
                mx = i;
            }
        }   

        for(int i=0; i<=mx; i++){
            if(((n>>i )& 1)==0){
                ans |= (1<<i);
            }
        }
        return ans;
    }
};
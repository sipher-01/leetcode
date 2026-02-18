class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        int first = n&1?1:0;
        int second = first==1?0:1;
        int msb = 32;
        for(int i=0; i<32; i++){
            if(n>>i & 1)msb = i;
        }
        for(int i=0; i<32; i++){
            cout<<((n>>i)&1)<<" ";
            if(i%2==1 && ((n>>i)&1)==first){
                return false;
            }
            if(i%2==0 && ((n>>i)&1)==second){
                return false;
            }
            if(msb==i)break;
        }
        return true;
    }
};
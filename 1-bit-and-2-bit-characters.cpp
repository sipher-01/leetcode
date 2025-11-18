class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i=0;
        int n=bits.size();
        while(i<n-1){
            if(bits[i]==1){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        cout<<i;
        bool ans = (i == (n-1))?true:false;
        return ans;
    }
};
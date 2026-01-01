class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        if(digits[n-1]==9){
            digits[n-1] = 0;
            carry = 1;
        }
        else{
            digits[n-1] += 1;
            carry = 0;
        }
        for(int i=n-2; i>=0; i--){
            if(carry == 1){
                if(digits[i]==9){
                    digits[i] = 0;
                }
                else{
                    digits[i] += 1;
                    carry = 0;
                }
            }
        }
        if(carry == 1){
            vector<int>ans(n+1,0);
            ans[0]=1;
            return ans;
        }
        return digits;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int i = n-1, j = m-1;
        string ans = "";
        int carry = 0;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j] =='1'){
                if(carry==1){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 1;
            }
            else if((a[i]=='1' && b[j]=='0') || (a[i]=='0' && b[j]=='1')){
                if(carry==1){
                    ans += '0';
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            else{
                if(carry==1){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                    carry = 0;
            }
            i--;
            j--;
        }
        cout<<carry<<endl;
        cout<<i<<" " << j<< " " <<endl<< ans<<" ";
        while(i>=0){
            if(a[i]=='1')
            {
                if(carry==1){
                    ans += '0';
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            else{
                if(carry==1){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 0;
            }
            i--;
        }
        cout<<ans<<" ";
        while(j>=0){
            if(b[j]=='1')
            {
                if(carry==1){
                    ans += '0';
                }
                else{
                    ans += '1';
                    carry = 0;
                }
            }
            else{
                if(carry==1){
                    ans += '1';
                }
                else{
                    ans += '0';
                }
                carry = 0;
            }
            j--;
        }
        if(carry==1){
            ans += '1';
        }
        cout<<ans<<" ";
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
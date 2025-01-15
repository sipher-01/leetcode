class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt_set = 0;
        int ans = 0;
        while(num2>0){
            cnt_set += num2&1;
            num2 >>=1; 
        }
        vector<int>bits;
        while(num1>0){
            bits.push_back(num1&1);
            num1 >>=1;
        }
        reverse(bits.begin(),bits.end());
        int n = bits.size();
        vector<int>res(n,0);
        for(int i=0; i<n; i++){
            if(bits[i]==1 && cnt_set>0){
                res[i]=1;
                cnt_set--;
            }
        }
        for(int i=n-1;i>=0; i--){
            if(res[i]==0 && cnt_set>0){
                res[i]=1;
                cnt_set--;
            }
        }
        while(cnt_set>0){
            res.push_back(1);
            cnt_set--;
        }
        int mul = 1;
        for(int i=res.size()-1; i>=0; i--){
            ans += res[i]*mul;
            mul *= 2;
        }
        return ans;
    }
};
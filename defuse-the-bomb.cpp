class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int>ans(n,0);
        if(k==0)return ans;
        int i,j;
        int sum = 0;
        if(k>0){
            i=1;
            j=k;
        }
        else{
            i=n-abs(k);
            j=n-1;
        }
        for (int m = i; m <= j; m++) {
            sum += code[m % n];
        }
        for(int l=0; l<n; l++){
                ans[l] = sum;
                sum -= code[i%n] ;
                sum += code[(j+1)%n];
                i++;
                j++;
        }
        return ans;
    }
};
class Solution {
public:
    bool compare(string& a, string &b){
        int n= a.size();
        int m= b.size();
        if(n!=m+1)return false;
        int i=0, j=0;
        if(m>n)return compare(b,a);
        while(i<n){
            if(a[i]!=b[j]){
                i++;
            }
            else{i++;
            j++;}
        }
        if(i==n && j==m)return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int maxi = 1;
        int n = words.size();
        sort(words.begin(),words.end(),[&](string a,string b){
            if(a.size()<b.size())return true;
            else return false;
        });
        vector<int>dp(n,1);
        for(int i=1; i<words.size(); i++){
            for(int j=0; j<i; j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i] = dp[j] +1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};
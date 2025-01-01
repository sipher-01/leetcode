class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>prefixSum(n,0);
        int cnt = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i]=='1'){
                cnt++;
            }
            prefixSum[i] = cnt;
        }
        cnt = 0;
        int ans = 0;
        for(int i=0; i<n-1; i++){
            if(s[i]=='0'){
                cnt++;
            }
            ans = max(ans,cnt + prefixSum[i+1]);
        }
        return ans;
    }
};
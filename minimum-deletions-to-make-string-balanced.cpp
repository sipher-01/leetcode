class Solution {
public:
    int minimumDeletions(string s) {
        
        // int bCount = 0;
        int n = s.length();
        // int dp = 0;
        vector<int>a(n+1,0);
        for(int i=0; i<n; i++){
            if(s[i] == 'a')a[i+1] = 1;
            a[i+1] += a[i] ;
        }
        int ans = min(a[n],n-a[n]);
        for (int i=1; i<=n; i++) {
            int leftB = i - a[i];
            int rightA = a[n] - a[i];
            ans = min (ans,leftB+rightA); 
        }
        return ans;
    }
};
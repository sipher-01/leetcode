class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();
        int cnt = 0;
        char prev = s[0];
        for(int i=0; i<n; i++){
            if(s[i]==prev){
                cnt++;
                continue;
            }
            if(cnt%2==0){
                cnt=1;
            }
            else{
                ans++;
                cnt=0;
            }
            prev = s[i];
        }
        return ans;
    }
};
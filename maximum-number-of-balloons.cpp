class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b[26];
        for(auto c: text){
            b[c-'a'] += 1;
        }
        int ans = INT_MAX;

        if(b[0]<1 || b[1]<1 || b[11]<2 || b[13]<1 || b[14]<2)return 0;
        ans = min({ans,b[0],b[1],b[11]/2,b[13],b[14]/2});
        return ans;
    }
};
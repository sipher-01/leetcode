class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        int terms = high - low;
        if(terms%2==0){
            ans += terms/2;
        }
        else{
            if(low%2==0){
                ans += terms/2 ;
            }
            else{
                ans += terms/2 + 1;
            }
        }
        ans = high%2==0?ans: ans+1;
        return ans;
    }
};
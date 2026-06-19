class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int alt = 0;
        for(auto it: gain){
            alt += it;
            ans = max(ans,alt);
        }

        return ans;
    }
};
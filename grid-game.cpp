#define ll long long
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        ll first = accumulate(grid[0].begin(),grid[0].end(),0LL);
        ll second = 0;
        ll ans = LONG_LONG_MAX;
        for(int i=0; i<n; i++){
            first -= grid[0][i];

            ans = min(ans,max(first,second));

            second += grid[1][i];
        }

        return ans;
    }
};
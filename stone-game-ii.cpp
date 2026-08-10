class Solution {
    int n;
    vector<int> prefix;
    int dp[105][105];

    int solve(int ind, int m) {
        if (ind >= n) return 0;
        
        // If current player can take all remaining piles, take them all
        if (2 * m >= n - ind) {
            return prefix[n] - prefix[ind];
        }
        
        if (dp[ind][m] != -1) return dp[ind][m];
        
        int max_stones = 0;
        int total_remaining = prefix[n] - prefix[ind];
        
        // Try all valid choices for X (1 <= x <= 2m)
        for (int x = 1; x <= 2 * m; x++) {
            // The current player gets: total remaining minus what the opponent can get next
            int opponent_score = solve(ind + x, max(m, x));
            max_stones = max(max_stones, total_remaining - opponent_score);
        }
        
        return dp[ind][m] = max_stones;
    }

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        prefix = vector<int>(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + piles[i];
        }
        
        memset(dp, -1, sizeof(dp));
        return solve(0, 1);
    }
};
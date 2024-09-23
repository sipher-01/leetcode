class Solution {
public:
    int solve(int i, string& s, unordered_set<string>& st, vector<int>& dp) {
        if (i >= s.size()) return 0; // Base case: no extra characters needed
        
        if (dp[i] != -1) return dp[i]; // Return already computed result
        
        // Assume the character at index i is an extra character
        int result = 1 + solve(i + 1, s, st, dp);
        
        string temp = "";
        for (int j = i; j < s.size(); j++) {
            temp += s[j]; // Build substring from index i to j
            if (st.count(temp)) { // If the substring is in the dictionary
                // Update the result with the minimum extra characters
                result = min(result, solve(j + 1, s, st, dp));
            }
        }
        
        return dp[i] = result; // Store result in memoization table
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size(), -1); // Initialize memoization table with -1
        return solve(0, s, st, dp); // Start recursion from index 0
    }
};
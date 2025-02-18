class Solution {
public:
    bool check(int num, int pre, char parent){
        if (pre == 0) return true; // If it's the first number, always valid
        if (parent == 'I') return num > pre; // Increasing condition
        return num < pre;
    }
    bool solve(int ind, string& pat, string& ans, int prev, vector<bool>& used) {
        if (ind == pat.length()) return true; // If we have processed all characters, we are done

        for (int i = 1; i <= 9; i++) {
            if (!used[i] && check(i, prev, pat[ind])) {
                used[i] = true;
                ans.push_back('0' + i); // Append to result

                if (solve(ind + 1, pat, ans, i, used)) return true;

                ans.pop_back(); // Backtrack
                used[i] = false;
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        vector<bool>used(10,false);
        string ans ="";
        for (int i = 1; i <= 9; i++) { 
            ans.push_back('0' + i);
            used[i] = true;
            if (solve(0, pattern, ans, i, used)) return ans;
            ans.pop_back();
            used[i] = false;
        }
        return "";
    }
};
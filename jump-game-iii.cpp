class Solution {
    int n;
public:
    bool solve(int ind, vector<bool>& visi, vector<int>& arr) {
        // Out of bounds or already visited
        if (ind < 0 || ind >= n || visi[ind]) return false;
        
        // Found a zero — success
        if (arr[ind] == 0) return true;
        
        // Mark visited before recursing (avoid cycles)
        visi[ind] = true;
        
        return solve(ind + arr[ind], visi, arr) || 
               solve(ind - arr[ind], visi, arr);
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool> visi(n, false);
        return solve(start, visi, arr);
    }
};
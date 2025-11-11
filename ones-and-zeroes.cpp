class Solution {
public:
    vector<vector<vector<int>>> memo;
    int fun(int i, vector<string>& strs, int m, int n, int zeroes, int ones){
        if(i>=strs.size()){
            return 0;
        }
        int& ans = memo[i][zeroes][ones];
        if (ans != -1) return ans;
        int zero = count(strs[i].begin(), strs[i].end(), '0');
        int one = (int)strs[i].size() - zero;
        int notTake = fun(i+1,strs,m,n,zeroes,ones);;
        int take = 0;
        if(zeroes + zero <= m && ones + one <= n){
            take = 1 + fun(i+1,strs,m,n,zeroes+zero, ones+one);
        }
        return ans = max(take, notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memo.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return fun(0,strs,m,n,0,0);
    }
};
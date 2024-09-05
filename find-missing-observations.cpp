class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum1 = accumulate(rolls.begin(),rolls.end(),0);
        int total_sum = mean *(m+n);
        int sum2 = total_sum - sum1;
        if (sum2 < n || sum2 > 6 * n) {
            return {};  
        }
        vector<int>ans(n,sum2/n);
        int rem = sum2%n;
        for(int i=0; i<rem; i++){
            ans[i]++;
        }
        return ans;

    }
};
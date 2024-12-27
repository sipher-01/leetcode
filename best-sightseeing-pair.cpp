class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int res = INT_MIN;
        vector<int>temp(n);
        for(int i=0; i<n; i++){
            temp[i] = values[i] + i;
        }
        int l = temp[0];
        for(int i=1; i<n; i++){
            int r = values[i] - i;
            res = max(res,l+r);
            l = max(l,temp[i]);
        }

        return res;
    }
};
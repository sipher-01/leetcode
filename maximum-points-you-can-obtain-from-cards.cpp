class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
    int l=0, r=0;
    int ans =0;
    int total_sum = accumulate(cardPoints.begin(),cardPoints.end(),0);
    int sum = 0;
    int windowSize = n-k;
    if(windowSize == 0)
        return total_sum;
    while(r<n){
        sum += cardPoints[r];
        while(r-l+1 == windowSize ){
            ans = max(ans,total_sum-sum);
            sum -= cardPoints[l];
            l++;
        }
        r++;
    }
    return ans;
    }
};
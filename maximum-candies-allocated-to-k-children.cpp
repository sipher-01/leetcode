class Solution {
public:
    bool check(int mid, vector<int>& candies, long long k){
        long long cnt = 0;

        for(auto it: candies){
            if(mid<=it)cnt+=it/mid;
            if(cnt>=k)return true;
        }

        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(candies.begin(),candies.end(),0LL);
        int maxi = *max_element(candies.begin(),candies.end());
        if(sum<k)return 0;
        int l = 1, r= maxi;
        int ans=0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(mid,candies,k)){
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    return ans;
    }
};
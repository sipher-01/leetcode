class Solution {
    using ll = long long;
    vector<int>temp;
    map<tuple<int,int>, int>dp;
public:
    int solve(int idx,int prev,int bit){
        if(idx>=temp.size()){
            if(bit!=0){
                return 0;
            }
            return INT_MIN;
        }
        auto key = make_tuple(idx,prev);
        if(dp.count(key))return dp[key];
        int ans = INT_MIN;
        if(temp[idx]>prev){
            int new_and = bit==-1?temp[idx]:bit&temp[idx];
            ans = 1 + solve(idx+1,temp[idx],new_and);
        }
        ans = max(ans ,solve(idx+1,prev,bit));
        return dp[key] = ans;
    }
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int b = 0; b<=30; b++){
            vector<int>t;
            for(auto it: nums){
                if((it>>b)&1)t.push_back(it);
            }
            vector<int>st;
            for(auto x: t){
                auto it = lower_bound(st.begin(),st.end(),x);
                if(it==st.end()){
                    st.push_back(x);
                }
                else{
                    *it = x;
                }
            }
            len = max(len,(int)st.size());
        }
        return len;
    }
};

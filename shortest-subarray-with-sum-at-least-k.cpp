class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>cs(n,0);
        deque<int>dq;
        int j = 0;
        int res = INT_MAX;
        while(j<n){
            cs[j] = j==0 ? nums[j]:(cs[j-1] + nums[j]);
            if(cs[j]>=k)res = min(res,j+1);
            while(!dq.empty() && cs[j]-cs[dq.front()]>=k){
                res = min(res,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cs[dq.back()]>=cs[j])dq.pop_back();
            dq.push_back(j);
            j++;
        }
        return res==INT_MAX?-1:res;
    }
};
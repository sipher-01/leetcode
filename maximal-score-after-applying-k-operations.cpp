class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int &it: nums){
            pq.push(it);
        }
        long long ans =0;
        while(k>0){
            int maxi = pq.top();
            pq.pop();
            ans += maxi;
            int val = ceil(maxi/3.0);
            pq.push(val);
            k--;
        }
        return ans;
    }
};
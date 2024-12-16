class Solution {
public:
#define p pair<int,int>
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int n = nums.size();
        vector<int>ans(n,0);
        for(int i=0; i<n; i++){
            pq.push({nums[i],i});
        }
        while(k--){
            auto tp = pq.top();
            pq.pop();
            int ele = tp.first;
            int i = tp.second;
            pq.push({ele*multiplier,i});
        }

        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int ele = node.first;
            int i = node.second;
            ans[i] = ele;
        }

        return ans;
    }
};
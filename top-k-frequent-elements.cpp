class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
           unordered_map<int,int>mp;
    priority_queue<pair<int,int>>pq;
    for(int it: nums){
        mp[it]++;
    }
    vector<int>ans;
    for(auto it: mp){
        pq.push({it.second,it.first});
        if(pq.size()>mp.size()-k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
    return ans;
    }
};
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,multiset<int>>mp;
        for(int i=0; i<arr.size(); i++){
            int cnt = __builtin_popcount(arr[i]);
            // mp[cnt].push_back(arr[i]);
            mp[cnt].insert(arr[i]);

        }
        vector<int>ans;
        for(auto it:mp){
            // sort(it.second.begin(),it.second.end());
            ans.insert(ans.end(),it.second.begin(),it.second.end());
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        vector<int>ans;
        for(auto it: arr){
            mp[it] = 0;
        }
        int i=1;
        for(auto &it: mp){
            it.second = i;
            i += 1;
        }
        for(int i=0; i<arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};
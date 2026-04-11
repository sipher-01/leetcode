class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto it: mp){
            auto vec = it.second;
            if(vec.size()>2){
                for(int i=1; i<vec.size()-1; i++){
                    int sum = abs(vec[i-1] - vec[i]) + abs(vec[i] - vec[i+1]) + abs(vec[i+1] - vec[i-1]) ;
                    ans = min(ans, sum); 
                }
            }
        }

        return ans==INT_MAX?-1:ans;
    }
};
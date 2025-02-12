class Solution {
public:
    int digits(int it){
        int sum = 0;
        while(it>0){
            int x = it%10;
            sum+=x;
            it /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(auto it: nums){
            mp[digits(it)].push_back(it);
        }
        int ans = -1;
        for(auto it: mp){
            if(it.second.size()>1){
                sort(it.second.begin(),it.second.end(),greater<int>());
                int a = it.second[0];
                int b = it.second[1];
                ans = max(ans,a+b);
            }
        }
        return ans;
    }
};
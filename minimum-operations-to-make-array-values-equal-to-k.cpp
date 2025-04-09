class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;

        for(auto it: nums){
            mp[it]++;
        }
        int ans = mp.size()-1;
        int first = *min_element(nums.begin(),nums.end());
        if(first<k)return -1;
        else if(first > k)ans++;
        return ans;

    }
};
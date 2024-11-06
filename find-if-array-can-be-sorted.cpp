class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<vector<int>>region;
        int n = nums.size();
        vector<int>temp;
        int prev = __builtin_popcount(nums[0]);
        for(int i=0; i<n; i++){
            if(__builtin_popcount(nums[i]) == prev){
                temp.push_back(nums[i]);
                prev = __builtin_popcount(nums[i]);
            }
            else{
                region.push_back(temp);
                temp.clear();
                temp.push_back(nums[i]);
                prev = __builtin_popcount(nums[i]);
            }
        }
        if(!temp.empty())region.push_back(temp);

        int prevMax = -1;
        for(auto &it: region){
            int currMin = *min_element(it.begin(),it.end());
            if(prevMax > currMin)return false;
            prevMax = *max_element(it.begin(),it.end());
        }
        return true;
    }
};
class Solution {
    set<vector<int>>permutations;
    int n;
public:
    void swap(int &a, int &b){
        int c = b;
        b=a;
        a=c;
    }
    void solve(int i,vector<int>&nums){
        if(i>=n){
            permutations.insert(nums);
            return;
        }
        for(int ind=i; ind<n; ind++){
            swap(nums[i],nums[ind]);
            solve(i+1,nums);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        solve(0,nums);
        vector<vector<int>>ans;
        for(auto it: permutations){
            ans.push_back(it);
        }
        return ans;
    }
};
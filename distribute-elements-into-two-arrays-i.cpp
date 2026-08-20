class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a,b;
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        int n = nums.size();
        for(int i=2; i<n; i++){
            if(a.back()>b.back())a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        vector<int>res(a.begin(),a.end());
        res.insert(res.end(),b.begin(),b.end());
        return res;
    }
};
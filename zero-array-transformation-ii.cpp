class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int k = queries.size();
        if(!formZeroArray(nums,queries,k))return -1;

        int l = 0, r = k;
        while(l<r){
            int mid = l + (r-l)/2;
            if(formZeroArray(nums,queries,mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }

    bool formZeroArray(vector<int>& nums, vector<vector<int>>&queries, int k){
        int n = nums.size();
        vector<int>diff(n+1,0);


        for(int i = 0; i<k; i++){
            int start = queries[i][0];
            int end = queries[i][1];
            int val = queries[i][2];
            diff[start] += val;
            diff[end+1] -= val;
        }

        int sum = 0;
        for(int i=0; i<n; i++){
            sum += diff[i];
            if(sum<nums[i])return false;
        }
        return true;
    }
};
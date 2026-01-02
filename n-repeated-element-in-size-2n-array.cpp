class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m = nums.size();
        int n = m/2;
        unordered_set<int>st;
        int l = 0;
        for(int i=0; i<m; i++){
            if(i-l+1 > 4){
                st.erase(nums[l]);
                l++;
            }
            if(st.count(nums[i])){
                return nums[i];
            }
            st.insert(nums[i]);
        }
        return -1;
    }
};
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i=0, j = 0;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        multiset<int>st;
        while(j<n){
            st.insert(nums[j]);
            mini = *st.begin(); 
            maxi = *st.rbegin(); 
            while((maxi-mini)>2){
                st.erase(st.find(nums[i]));
                mini = *st.begin();
                maxi = *st.rbegin();
                i++;
            }
            ans += (j-i+1);
            j++;
        }

        return ans;   
    }
};
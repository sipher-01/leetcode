class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        int avg = (sum/n);
        unordered_set<int>st;
        int ans = 0;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        int num = avg+1;
        while(true){
            if (st.find(num)==st.end()){
                if (num>0)
                {ans = num;
                break;}
            }
            num++;
        }
        return ans;
    }
};
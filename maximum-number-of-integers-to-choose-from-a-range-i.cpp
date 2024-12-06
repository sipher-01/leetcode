class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans=0;
        set<int>st;
        for(auto it: banned){
            st.insert(it);
        }
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(st.find(i)==st.end() && sum + i <= maxSum){
                sum += i;
                ans++;
            }
        }
        return ans;
    }
};
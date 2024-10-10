class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        stack<int>st;
        int ans = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (st.empty() || arr[st.top()] > arr[i]) {
                st.push(i);  
            }
        }
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                ans = max(ans,i-st.top());
                st.pop();
            }   
        }
        return ans;
    }
};
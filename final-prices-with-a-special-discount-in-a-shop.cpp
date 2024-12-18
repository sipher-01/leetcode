class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n = prices.size();
        vector<int>disc(n,-1);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && prices[st.top()]>prices[i]){
                st.pop();
            }
            if(!st.empty())disc[i] = st.top();
            st.push(i);
        }

        for(int i=0; i<n; i++){
           if(disc[i]!=-1) disc[i] = prices[i] - prices[disc[i]];
           else disc[i] = prices[i];
        }
        return disc;
    }
};
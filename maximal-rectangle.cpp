class Solution {
public:
    int longestHistogram(vector<int>&hist){
        stack<int>st;
        int maxA = 0;
        int n = hist.size();
        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || hist[st.top()]>hist[i])){
                int height = hist[st.top()];
                st.pop();
                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i-1 - st.top();
                }
                maxA = max(maxA,height*width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>hist(m,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    hist[j]++;
                }
                else{
                    hist[j] = 0;
                }
            }
            int maxA = longestHistogram(hist);
            ans = max(maxA,ans);
        }
        return ans;
    }
};
class Solution {
public:

    int longestHistogram(vector<int>&a, int n){
        stack<int>st;
        vector<int>prev(n),next(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty())prev[i]=-1;
            else{
                prev[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(st.empty())next[i]=n;
            else{
                next[i] = st.top();
            }
            st.push(i);
        }
        int res=0;
        for(int i=0; i<n; i++){
            int length = next[i] - prev[i] - 1;
            int height = a[i];
            int area = length*height;
            res = max(res,area);
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int>histogram(m,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }
                else{
                    histogram[j] = 0;
                }
            }
            int rect = longestHistogram(histogram,m);
            ans = max(ans,rect);
        }

        return ans;
    }
};
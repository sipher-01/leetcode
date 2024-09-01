class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        if(m*n!=original.size())return ans;
        int cnt=0;
        vector<int>temp;
        for(int i=0; i<m*n; ++i){
            cnt++;
            temp.push_back(original[i]);
            if(cnt==n){
                ans.push_back(temp);
                cnt=0;
                temp.clear();
            }
        }
        return ans;
    }
};
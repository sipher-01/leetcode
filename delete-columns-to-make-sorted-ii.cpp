class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int unresolved = n-1;
        vector<int>resolved(n,0);
        int res = 0;
        for(int j=0; j<m && unresolved>0; j++){
            bool flag = false;
            for(int i=1; i<n; i++){
                if(!resolved[i] && strs[i][j]<strs[i-1][j]){
                    flag = true;
                    break;
                }
            }
            if(flag){
                res++;
                continue;
            }
            for(int i=1; i<n ; i++){
                if(!resolved[i] && strs[i][j]>strs[i-1][j]){
                    resolved[i] = 1;
                    unresolved--;
                }
            }
        }
        return res;
    }
};
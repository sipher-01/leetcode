class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>mp;
        int n = A.size();
        vector<int>ans(n,0);
        int i=0;
        int count = 0;
        while(i<n ){
            mp[A[i]]++;
            if(mp[A[i]]==2) count += 1;
            mp[B[i]]++;
            if(mp[B[i]]==2) count += 1;
            ans[i] = count;
            i++;
        }
        return ans;
    }
};
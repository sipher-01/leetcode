class Solution {
    unordered_map<int,int>mp;
public:
    int solve(int i, int j, vector<int>&arr){
        int target = arr[j] - arr[i];
        if(mp.count(target) && mp[target]<i){
            int k = mp[target];
            return 1 + solve(k,i,arr);
        }
        return 2;
    } 
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        int res = 0;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                int length = solve(j,k,arr);
                if(length>=3){
                    res = max(res,length);
                }
            }
        }
        return res;
    }
};
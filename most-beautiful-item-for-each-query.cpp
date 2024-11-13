class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {       sort(items.begin(),items.end());
        vector<int>ans;
        int n = queries.size();
        int m = items.size();
        int maxi = 0;
        for(auto &it: items){
            if(maxi>it[1]){
                it[1] = maxi;
            }
            else{
                maxi = it[1];
            }
        }
        for(int i=0; i<n; i++){
            int l=0,r=m-1;
            bool found = false;
            while(l<=r){
                int mid = (l+r)/2;
                if(items[mid][0]<=queries[i]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }
            ans.push_back(r == -1 ? 0 : items[r][1]);
        }
        return ans;
    }
};
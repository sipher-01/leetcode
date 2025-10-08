class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0; i<n; i++){
           long long x = ceil((double)success/spells[i]);
           cout<<x<<" ";
            int ind = lower_bound(potions.begin(),potions.end(),x)-potions.begin();
            cout<<ind<<endl;
            int num = m-ind;
            ans[i] = num;
        }
        return ans;
    }
};
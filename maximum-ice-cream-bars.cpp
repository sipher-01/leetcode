class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        int total = 0;

        for(auto it: costs){
            if((total  + it)>coins)break;
            total += it;
            ans++;
        }

        return ans;
    }
};
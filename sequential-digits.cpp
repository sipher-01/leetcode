class Solution {
public:
    void solve(int a, int prev, vector<int>& total){
        if(prev==9)return ;
        a *= 10;
        prev += 1;
        total.push_back(a+prev);
        solve(a+prev,prev,total);
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>total;
        for(int i=1; i<9; i++){
            solve(i,i,total);
        }
        sort(total.begin(),total.end());
        vector<int>ans;
        for(auto it: total){
            if(it>=low && it<=high){
                ans.push_back(it);
            }
            if(it>high)break;
        }
        return ans;
    }
};
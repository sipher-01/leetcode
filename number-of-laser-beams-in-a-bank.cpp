class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = count(bank[0].begin(),bank[0].end(),'1');
        int m = bank.size();
        int ans = 0;
        for(int i=1; i<m; i++){
            int curr = count(bank[i].begin(),bank[i].end(),'1');
            if(curr==0)continue;
            ans += (curr*prev);
            prev = curr;
        }

        return ans;
    }
};
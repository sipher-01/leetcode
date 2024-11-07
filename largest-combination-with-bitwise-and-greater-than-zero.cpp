class Solution {
public:
    int solve(int i, vector<int>& c, int track){
        if(i==c.size())return 0;
        int np = solve(i + 1, c, track);
        
        int p = 0;
        int check = track & c[i];
        if (track == 0 || check > 0) { 
            p = 1 + solve(i + 1, c, check > 0 ? check : c[i]);
        }
        return max(p,np);
    }
    int largestCombination(vector<int>& candidates) {
        int track = 0;
        int n = candidates.size();
        int ans = -1;
        // return solve(0,candidates,track);
        for(int mask = 0; mask<32; mask++){
            int temp = 0;
            for(int i=0; i<n; i++){
                int check = candidates[i]&1<<mask;
                temp += (check>0) ? 1 : 0;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};
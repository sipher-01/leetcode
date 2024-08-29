class Solution {
public:
    void dfs(int ind, vector<vector<int>>& stones, vector<bool>& visi, int n){
        visi[ind]=true;
        for(int i=0; i<n; i++){
            if(!visi[i]){
                if(stones[i][0] == stones[ind][0])dfs(i,stones,visi,n);
                if(stones[i][1] == stones[ind][1])dfs(i,stones,visi,n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool>visi(n);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!visi[i]){
                dfs(i,stones,visi,n);
                cnt++;
            }
        }
        return n-cnt;
    }
};
class Solution {
    #define f(i,n) for(int i=0; i<n; i++)
    #define f(i,m) for(int i=0; i<m; i++)
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vector<int>row(m);
        vector<int>col(n);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    row[i]++;
                    col[j]++;
                }
            }
        }
        // f(i,m){
        //     cout<<row[i]<<endl;
        // }
        // f(i,n){
        //     cout<<col[i]<<" ";
        // }
        int cnt = 0;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            if(row[r]>1 || col[c]>1){
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
    int n;
    int r[4] = {-1,0,1,0};
    int c[4] = {0,1,0,-1};
public:
    bool is_valid(int i, int j){
        return i>=0 && i<n && j>=0 && j<n;
    }
    int DFS(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&visi,int id){
        visi[i][j] = true;
        grid[i][j] = id;
        int s = 1;
        for(int d=0; d<4; d++){
            int nr = i + r[d];
            int nc = j + c[d];
            if(is_valid(nr,nc) && grid[nr][nc]==1 && !visi[nr][nc]){
                s += DFS(grid,nr,nc,visi,id);
            }
        }
        return s;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int unq_id = 2;
        unordered_map<int,int>mp;
        n = grid.size();
        vector<vector<bool>>visi(n,vector<bool>(n,false));
        int island = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!visi[i][j] && grid[i][j]==1){
                    int s = DFS(grid,i,j,visi,unq_id);
                    mp[unq_id] = s;
                    island = max(island,s);
                    unq_id++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    int largest = 1;
                    unordered_set<int>st;
                    for(int k=0; k<4; k++){
                        int nr = i + r[k];
                        int nc = j + c[k];
                        if(is_valid(nr,nc) && grid[nr][nc]>0 ){
                            st.insert(grid[nr][nc]);
                        }
                    }
                    for(auto it: st){
                        largest += mp[it];
                    }
                    island = max(island,largest);
                }
            }
        }

        return island;
    }
};
class Solution {
public:
    bool check(int r, int c,int n, vector<vector<int>>& city){
        bool flag = false;
        for(int i=r-1; i>=1; i--){
            if(city[i][c]==1)
            {
                flag = true;
                break;
                }
            else continue;
        }
        if(!flag) return false;
        flag = false;
        for(int i=c+1; i<n+1; i++){
            if(city[r][i]==1)
            {
                flag = true;
                break;
                }
            else continue;;
        }

        if(!flag) return false;
        flag = false;

        for(int i=r+1; i<n+1; i++){
            if(city[i][c]==1)
            {
                flag = true;
                break;
                }
            else continue;
        }

        if(!flag) return false;
        flag = false;

        for(int i=c-1; i>=1; i--){
            if(city[r][i]==1)
            {
                flag = true;
                break;
                }
            else continue;
        }
        if(!flag) return false;
        return true;
    }
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // vector<vector<int>>city(n+1,vector<int>(n+1,0));
        // for(auto it: buildings){
        //     city[it[0]][it[1]] = 1;
        // }
        // int ans =0;
        // for(auto it: buildings){
        //     int row = it[0];
        //     int col = it[1];
        //     if(row>=1 && row<n+1 && col>=1 && col<n+1 && check(row,col,n,city)){
        //             ans++;
        //     }
        // }
        // return ans;
        vector<int>maxR(n+1);
        vector<int>minR(n+1,n+1);
        vector<int>maxC(n+1);
        vector<int>minC(n+1,n+1);
        for(auto it: buildings){
            int u = it[0];
            int v = it[1];
            maxR[v] = max(maxR[v],u);
            minR[v] = min(minR[v],u);
            maxC[u] = max(maxC[u],v);
            minC[u] = min(minC[u],v);
        }
    int ans = 0;
        for(auto it: buildings){
            int u = it[0];
            int v = it[1];
            if(u > minR[v] && u<maxR[v] && v>minC[u] && v<maxC[u]){
                ans++;
            }
        }
        return ans;
    }
};
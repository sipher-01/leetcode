class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        int m = edges.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(i==j)dist[i][j]=0;
            }
        }
        for(auto it: edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int k=0; k<n; ++k){
            for(int i=0; i<n; ++i){
                for(int j=0; j<n; ++j){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        vector<int>cities(n,0);
        for(int i=0; i<n; i++){
            int a = 0;
            for(int j=0; j<n; j++){
                if(i!=j && dist[i][j]<=distanceThreshold){
                    a++;
                }
            }
            cities[i] = a;
        }
        int ans=1e9;
        for(int i=0; i<n; i++){
            ans = min(cities[i],ans);
        }
        int res = 0;
        for(int i=0; i<n; i++){
            if(cities[i]==ans)res = i;
        }
        return res;
    }
};
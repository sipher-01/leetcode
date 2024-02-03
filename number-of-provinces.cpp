class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected,int n, vector<int> &visi){
        visi[node]=1;
        for(int j=0;j<n;j++){
        if(isConnected[node][j] && (visi[j] == 0)){
                dfs(j,isConnected,n,visi);
        }
    }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans=0;
        int n = isConnected.size();
        vector<int>visi(n+1,0);
        for(int i=0; i<n; i++){
            if(visi[i]==0){
                ans +=1;
                dfs(i,isConnected,n,visi);
            }
        }
        return ans;
    }
};
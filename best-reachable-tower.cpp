class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int>ans(2,INT_MAX);
        int quality = -1;
        // sort(towers.begin(),towers.end(),[](vector<int>a,vector<int>b){
        //     if(a[0]==b[0]){
        //         return a[1]<b[1];
        //     }
        //     return a[0]<b[0];
        // });
        int n = towers.size();
        for(int i=0; i<n; i++){
            int manhat_dist = abs(towers[i][0]-center[0]) + 
            abs(towers[i][1]-center[1]);
            if(manhat_dist<=radius){
                if(towers[i][2]>quality){
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                    quality = max(quality,towers[i][2]); 
                }
                else if(towers[i][2]==quality){
                    if(towers[i][0] < ans[0] || 
                       (towers[i][0]==ans[0] && towers[i][1]<ans[1])){
                            ans[0] = towers[i][0];
                            ans[1] = towers[i][1]; 
                    }
                }
            }
        }
        if(ans[0]==INT_MAX || ans[1]== INT_MAX){
            return {-1,-1}; 
        }
        return ans;
    }
};
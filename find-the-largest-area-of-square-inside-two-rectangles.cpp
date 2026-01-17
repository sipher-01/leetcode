class Solution {
public:
using ll = long long;
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll ans = 0;
        int side = 0;
        int n = topRight.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n && i!=j; j++){
                if( (topRight[i][0]<bottomLeft[j][0] && bottomLeft[i][0]>topRight[j][0]) || 
                (topRight[i][1] < bottomLeft[j][1] && bottomLeft[i][1]>topRight[j][1])){
                    continue;
                }
                else{
                    int width  = min(topRight[i][0], topRight[j][0]) 
                            - max(bottomLeft[i][0], bottomLeft[j][0]);

                    int height = min(topRight[i][1], topRight[j][1]) 
                            - max(bottomLeft[i][1], bottomLeft[j][1]);
                    if(width > 0 && height > 0)
                    side = max(side, min(width, height));
                }
            }
        }
        ans = 1ll*side*side;
        return ans;
    }
};
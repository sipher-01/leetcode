class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int v = m+2;
        int h = n+2;
        int width = 0;
        int height = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side ;
        // if(vBars.size()<hBars.size()){
            int cnt = 2;
            int prev = -1;
            for(int i=0; i<vBars.size(); i++){
                if(i==0){
                    prev= vBars[i];
                }
                else if(vBars[i-1]+1==vBars[i]){
                    cnt++;
                }
                else{
                    cnt = 2;
                }
                width = max(width,cnt);
            }
            // side = width;
             cnt = 2;
            prev = -1;
            for(int i=0; i<hBars.size(); i++){
                if(i==0){
                    prev= hBars[i];
                }
                else if(hBars[i-1]+1==hBars[i]){
                    cnt++;
                }
                else{
                    cnt = 2;
                }
                height = max(height,cnt);
            }
            // side = height;
        // }
        side = min(height, width);
        return side*side;
    }
};
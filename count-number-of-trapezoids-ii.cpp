class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<float,vector<float>>slopeIntercept;
        unordered_map<int,vector<float>>midpoint;
        int n = points.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int dx = x2-x1;
                int dy = y2-y1;
                float slope,intercept;
                if(x1==x2){
                    slope = 1e9+7;
                    intercept = x1;
                }
                else{
                    slope = (float)(y2-y1)/(x2-x1);
                    intercept = (float)(y1*dx - x1*dy)/dx;
                }
                int key = (x1+x2)*10000 + (y1+y2);
                slopeIntercept[slope].push_back(intercept);
                midpoint[key].push_back(slope);
            }
        }
        int res = 0;
        for(auto &it: slopeIntercept){
            map<float,int>mp;
            for(auto cnt:it.second){
                mp[cnt]++;
            }
            int prev = 0;
            for(auto i: mp){
                int count = i.second;
                res += prev*count;
                prev +=  count;
            }
        }
        for(auto &it: midpoint ){
            map<float,int>mp;
            for(auto cnt:it.second){
                mp[cnt]++;
            }
            int prev = 0;
            for(auto i: mp){
                int count = i.second;
                res -= prev*count;
                prev +=  count;
            }
        }
        return res;
    }
};
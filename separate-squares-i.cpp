class Solution {
public:
    bool check(double mid, vector<vector<int>>& squares, double total){
        double base = 0.0;

        for(auto &s: squares){
            double x = s[0], y = s[1], l = s[2];
            int top=y+l, bot = y;
            if(mid>top){
                base += (l*l);
            }
            else if(mid>bot){
                base += (l*(mid - y));
            }
        }

        return (base >= (total/2.0));
    }

    double separateSquares(vector<vector<int>>& squares) {
        double ans = 0.00000;
        double l = 1e18, h=-1e18;
        double total = 0.0;
        for(auto &it: squares){
            double x = it[0], y = it[1], s = it[2];
            total += (s*s);
            l = min(l,x);
            h = max(h,y+s);
        }


        while(h-l > 1e-5){
            double mid_y = l + (h-l)/2.0;
                ans = mid_y;
            if(!check(mid_y,squares,total)){
                l = mid_y;
            }
            else{
                h = mid_y;
            }
        }
        return ans;
    }
};
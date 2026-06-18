class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hr = hour*30 + minutes*0.5;
        double mint = minutes*6;
        double angle = abs(hr-mint);
        double second = 360.0 - angle;
        double ans = min(angle,second);
        return ans;
    }
};
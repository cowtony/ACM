class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deg_m = minutes * 6;
        double deg_h = (hour % 12) * 30 + minutes / 2.0;
        double res = abs(deg_h - deg_m);
        return min(res, 360 - res);
    }
};

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        double x = 100, next_x = 0, y = 100, next_y = 0;
        while (abs(x - next_x) > 1e-8 or abs(y - next_y) > 1e-8) {
            x = next_x;
            y = next_y;
            next_x = getX(positions, y);
            next_y = getY(positions, next_x);
        }
        
        double res = 0;
        for (auto p : positions) {
            res += sqrt((x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]));
        }
        return res;
    }
    
    double getX(vector<vector<int>>& positions, double y) {
        double x_max = 100, x_min = 0;
        while (x_max - x_min > 1e-9) {
            double x_mid = (x_min + x_max) / 2.0;
            double dirivative_x = 0;
            for (auto p : positions) {
                dirivative_x += (x_mid - p[0]) / sqrt((x_mid - p[0]) * (x_mid - p[0]) + (y - p[1]) * (y - p[1]));
            }
            if (dirivative_x > 0) {
                x_max = x_mid;
            } else {
                x_min = x_mid;
            }
        }
        return x_min;
    }
    
    double getY(vector<vector<int>>& positions, double x) {
        double y_max = 100, y_min = 0;
        while (y_max - y_min > 1e-9) {
            double y_mid = (y_min + y_max) / 2.0;
            double dirivative_y = 0;
            for (auto p : positions) {
                dirivative_y += (y_mid - p[1]) / sqrt((x - p[0]) * (x - p[0]) + (y_mid - p[1]) * (y_mid - p[1]));
            }
            if (dirivative_y > 0) {
                y_max = y_mid;
            } else {
                y_min = y_mid;
            }
        }
        return y_min;
    }
};

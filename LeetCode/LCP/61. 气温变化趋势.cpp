class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        int days = 0, max_days = 0;
        for (int i = 1; i < temperatureA.size(); i++) {
            days++;
            if (sign(temperatureA[i] - temperatureA[i - 1]) != sign(temperatureB[i] - temperatureB[i - 1])) {
                days = 0;
            }
            
            max_days = max(max_days, days);
        }
        return max_days;
    }

    int sign(int x) {
        if (x > 0) {
            return 1;
        } else if (x < 0) {
            return -1;
        } else {
            return 0;
        }
    }
};

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e8;
        while (low < high) {
            int mid = (low + high) / 2;
            if (timeTook(dist, mid) > hour) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return high == 1e8? -1 : high;
    }

    double timeTook(const vector<int>& dist, int speed) {
        double result = 0;
        for (int i = 0; i < dist.size() - 1; i++) {
            result += ceil(dist[i] / double(speed));
        }
        return result + dist.back() / double(speed);
    }
};

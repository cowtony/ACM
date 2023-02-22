class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 1e8;
        while (low < high) {
            int mid = (low + high) / 2;
            if (daysToShip(weights, mid) > days) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int daysToShip(const vector<int>& weights, int capacity) {
        int days = 0;
        int sum = 0;
        for (int weight : weights) {
            if (sum + weight <= capacity) {
                sum += weight;
            } else {
                days++;
                sum = weight;
                if (sum > capacity) {
                    return INT_MAX;
                }
            }
        }
        return days + 1;
    }
};

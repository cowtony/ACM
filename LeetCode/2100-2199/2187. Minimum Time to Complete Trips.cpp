class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 0, high = 1e14;
        while (low < high) {
            long long mid = (low + high) / 2;
            if (getTrips(time, mid) >= totalTrips) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    long long getTrips(const vector<int>& time, long long time_limit) {
        long long result = 0;
        for (int t : time) {
            result += time_limit / t;
        }
        return result;
    }
};

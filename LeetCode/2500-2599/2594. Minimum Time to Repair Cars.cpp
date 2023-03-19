class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        
        long long low = 1, high = LONG_MAX;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canFix(ranks, cars, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool canFix(const vector<int>& ranks, int cars, long long time) {
        for (int rank : ranks) {
            cars -= floor(sqrt(time / rank));
            if (cars <= 0) {
                return true;
            }
        }
        return cars <= 0;
    }
};

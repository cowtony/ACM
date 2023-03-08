class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1e9;
        while (low < high) {
            int mid = (low + high) / 2;
            if (hours(piles, mid) > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int hours(const vector<int>& piles, int k) {
        int result = 0;
        for (int pile : piles) {
            result += (pile + k - 1) / k;
        }
        return result;
    }
};

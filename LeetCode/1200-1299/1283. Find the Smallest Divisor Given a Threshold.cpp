class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = (low + high) / 2;
            if (getSumResult(nums, mid) <= threshold) {
                high = mid;
            } else {  // > threshold
                low = mid + 1;
            }
        }
        return high;
    }

    int getSumResult(const vector<int>& nums, int divisor) {
        int sum = 0;
        for (int num : nums) {
            sum += (num - 1) / divisor + 1;
        }
        return sum;
    }
};

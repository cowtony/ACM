class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = INT_MAX;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (numOfSplits(nums, mid) > k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int numOfSplits(const vector<int>& nums, int maximum) {
        int count = 1;
        int sum = 0;
        for (int num : nums) {
            if (num > maximum) {
                return INT_MAX;
            }
            sum += num;
            if (sum > maximum) {
                count++;
                sum = num;
            }
        }
        return count;
    }
};

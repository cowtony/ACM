// Binary search the answer.
// DP timeout.
class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = (low + high) / 2;
            int kk = maximumRobbed(nums, mid);
            if (kk < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    // Greedy
    int maximumRobbed(const vector<int>& nums, int capacity) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= capacity) {
                result++;
                i++;  // skip next for adjacent constraint.
            }
        }
        return result;
    }
};

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0, hi = nums.back() - nums.front();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (countDistanceSmallerOrEqualTo(nums, mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return hi;
    }

    // O(n)
    int countDistanceSmallerOrEqualTo(const vector<int>& nums, int target) {
        int count = 0;
        for (int l = 0, r = 1; l < nums.size(); l++) {
            while (r < nums.size() && nums[r] - nums[l] <= target) {
                r++;
            }
            count += r - l - 1;
        }
        return count;
    }
};

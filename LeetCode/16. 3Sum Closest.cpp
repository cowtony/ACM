class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int close_sum;
        for (int i = 0; i < nums.size() - 2; i++) {
            
            if (i > 0 and nums.at(i) == nums.at(i - 1)) {
                continue;
            }
            int two_sum = twoSumClosest(nums, i + 1, target - nums.at(i));
            int diff = abs(two_sum + nums.at(i) - target);
            if (min_diff > diff) {
                min_diff = diff;
                close_sum = two_sum + nums.at(i);
            }
        }
        return close_sum;
    }
    
    int twoSumClosest(vector<int>& nums, int start_index, int target) {
        int min_diff = INT_MAX;
        int close_sum;
        int lo = start_index, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums.at(lo) + nums.at(hi);
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                lo++;
                if (target - sum < min_diff) {
                    min_diff = target - sum;
                    close_sum = sum;
                }
            } else if (sum > target) {
                hi--;
                if (sum - target < min_diff) {
                    min_diff = sum - target;
                    close_sum = sum;
                }
            }
        }
        return close_sum;
    }
};

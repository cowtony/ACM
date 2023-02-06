class Solution {
public:
    vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001, 0));
    
    int minCost(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int trimmed = 0;
        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) {
                trimmed += 2;
            } else if (count[num] > 2) {
                trimmed++;
            }
        }
        return minCost(nums, 0, nums.size(), count, trimmed, k);
    }
    
    int minCost(const vector<int>& nums, int begin, int end, unordered_map<int, int> count_right, int trimmed_right, int k) {
        if (dp[begin][end] != 0) {
            return dp[begin][end];
        }
        
        // No cut cost
        
        int min_cost = trimmed_right + k;
        int trimmed_left = 0;
        unordered_map<int, int> count_left;
        for (int cut = begin + 1; cut < end; cut++) {
            count_left[nums[cut - 1]]++;
            if (count_left[nums[cut - 1]] == 2) {
                trimmed_left += 2;
            } else if (count_left[nums[cut - 1]] > 2) {
                trimmed_left++;
            }
            count_right[nums[cut - 1]]--;
            if (count_right[nums[cut - 1]] == 1) {
                trimmed_right -= 2;
            } else if (count_right[nums[cut - 1]] >= 2) {
                trimmed_right--;
            }
            int cost = minCost(nums, begin, cut, count_left, trimmed_left, k) + minCost(nums, cut, end, count_right, trimmed_right, k);
            // if (cut == 2) {
            //     std::cout << minCost(nums, begin, cut, k) << minCost(nums, cut, end, k) << endl;
            // }
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        
        dp[begin][end] = min_cost;
        return min_cost;
    }
};
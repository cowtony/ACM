class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.empty() or limit < 0) {
            return -1;
        }

        deque<int> max_stack;
        deque<int> min_stack;
        int max_len = 0;
        for (int lo = 0, hi = 0; hi < nums.size(); hi++) {
            while (!max_stack.empty() and nums[max_stack.back()] <= nums[hi]) {
                max_stack.pop_back();
            }
            max_stack.push_back(hi);
            while (!min_stack.empty() and nums[min_stack.back()] >= nums[hi]) {
                min_stack.pop_back();
            }
            min_stack.push_back(hi);
            
            while (nums[max_stack.front()] - nums[min_stack.front()] > limit) {
                lo++;
                if (max_stack.front() < lo) {
                    max_stack.pop_front();
                }
                if (min_stack.front() < lo) {
                    min_stack.pop_front();
                }
            }
            max_len = max(max_len, hi - lo + 1);
        }
        return max_len;
    }
};

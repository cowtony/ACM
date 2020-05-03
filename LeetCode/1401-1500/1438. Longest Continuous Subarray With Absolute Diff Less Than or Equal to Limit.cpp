class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        if (nums.empty() or limit < 0) {
            return -1;
        }
        
        int lo = 0, hi = 0;
        deque<int> max_stack;
        deque<int> min_stack;
        int max_len = 0;
        while (lo <= hi and lo < nums.size() and hi < nums.size()) {
            while (!max_stack.empty() and nums[max_stack.back()] <= nums[hi]) {
                max_stack.pop_back();
            }
            max_stack.push_back(hi);
            while (!min_stack.empty() and nums[min_stack.back()] >= nums[hi]) {
                min_stack.pop_back();
            }
            min_stack.push_back(hi);
            
            if (nums[max_stack.front()] - nums[min_stack.front()] > limit) {
                lo++;
                if (max_stack.front() < lo) {
                    max_stack.pop_front();
                }
                if (min_stack.front() < lo) {
                    min_stack.pop_front();
                }
            } else {
                max_len = max(max_len, hi - lo + 1);
                hi++;
            }
        }
        return max_len;
    }
};

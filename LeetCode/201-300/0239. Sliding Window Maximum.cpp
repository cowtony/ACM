class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq; // Monotonic decrease stack.
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() and nums[i] > nums[dq.back()]) {
                dq.pop_back();
                
            }
            dq.push_back(i);
            if (i >= k - 1) {
                if (!dq.empty() and dq.front() <= i - k) {
                    dq.pop_front();
                }
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

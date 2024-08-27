class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (int i = 0; i < nums.size(); i++) {
            min_heap.push({nums[i], i});
        }

        while (k--) {
            auto [val, idx] = min_heap.top();
            min_heap.pop();
            min_heap.push({val * multiplier, idx});
        }

        while (!min_heap.empty()) {
            auto [val, idx] = min_heap.top();
            min_heap.pop();
            nums[idx] = val;
        }

        return nums;
    }
};

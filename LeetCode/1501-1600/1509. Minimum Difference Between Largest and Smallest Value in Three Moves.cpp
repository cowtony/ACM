class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() < 5) {
            return 0;
        }

        priority_queue<int> min_heap;
        priority_queue<int, vector<int>, greater<int>> max_heap;
        for (int num : nums) {
            max_heap.push(num);
            if (max_heap.size() > 4) {
                max_heap.pop();
            }
            min_heap.push(num);
            if (min_heap.size() > 4) {
                min_heap.pop();
            }
        }
        
        stack<int> max_stack;
        while (!max_heap.empty()) {
            max_stack.push(max_heap.top());
            max_heap.pop();
        }
        
        int res = INT_MAX;
        while (!min_heap.empty()) {
            res = min(res, max_stack.top() - min_heap.top());
            max_stack.pop();
            min_heap.pop();
        }
        
        return res;
    }
};

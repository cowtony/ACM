class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int min_val = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1) {
                num *= 2;
            }
            min_val = min(min_val, num);
            pq.push(num);
        }

        int result = pq.top() - min_val;
        while (pq.top() % 2 == 0) {
            min_val = min(min_val, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
            result = min(result, pq.top() - min_val);
        }
        return result;
    }
};

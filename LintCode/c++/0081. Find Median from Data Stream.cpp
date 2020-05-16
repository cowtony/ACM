class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int>> small;
        priority_queue<int> large;
        
        vector<int> medians;
        for (int num : nums) {
            if (large.empty() or num <= large.top()) {
                large.push(num);
            } else {
                small.push(num);
            }
            // balance
            if (large.size() < small.size()) {
                large.push(small.top());
                small.pop();
            } else if (large.size() >= small.size() + 2) {
                small.push(large.top());
                large.pop();
            }
            
            medians.push_back(large.top());
        }
        return medians;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> large, small;
        vector<double> medians;
        for (int i = 0; i < nums.size(); i++) {
            // Add new element.
            if (small.empty() or nums[i] <= *small.rbegin()) {
                small.insert(nums[i]);
            } else {
                large.insert(nums[i]);
            }
            // Remove old element.
            if (i >= k) {
                if (!large.empty() and nums[i - k] >= *large.begin()) {
                    large.erase(large.find(nums[i - k]));
                } else {
                    small.erase(small.find(nums[i - k])); 
                }
            }
            // Balance.
            while (small.size() >= large.size() + 2) {
                large.insert(*small.rbegin());
                small.erase(small.find(*small.rbegin()));
            }
            while (large.size() > small.size()) {
                small.insert(*large.begin());
                large.erase(large.find(*large.begin()));
            }
            // Output
            if (i >= k - 1) {
                if (k % 2 == 0) {
                    medians.push_back((double(*small.rbegin()) + *large.begin()) / 2.0);
                } else {
                    medians.push_back(*small.rbegin());
                }
            }
        }
        return medians;
    }
};

class Solution {
public:
    Solution(vector<int>& w) {
        prefix_sum.push_back(0);
        for (int weight : w) {
            prefix_sum.push_back(prefix_sum.back() + weight);
        }
    }
    
    int pickIndex() {
        int r = rand() % prefix_sum.back();
        int lo = 0, hi = prefix_sum.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (r >= prefix_sum[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo - 1;
    }

private:
    vector<int> prefix_sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> inc_list;
        for (int num : nums) {
            // Use binary search to put Number in to correctly place of list.
            int lo = 0, hi = inc_list.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (inc_list[mid] < num) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            if (lo == inc_list.size()) {
                inc_list.push_back(num);
            } else {
                inc_list[lo] = num;
            }
        }
        return inc_list.size();
    }
};

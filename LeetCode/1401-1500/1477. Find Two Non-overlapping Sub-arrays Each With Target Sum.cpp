class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // Use sliding window to calculate the length of subarray from left to right and right to left.
        vector<int> len_l(arr.size(), INT_MAX >> 1);
        vector<int> len_r(arr.size(), INT_MAX >> 1);
        for (int lo = 0, hi = 0, sum = 0; hi < arr.size(); hi++) {
            sum += arr[hi];
            while (sum > target) {
                sum -= arr[lo];
                lo++;
            }
            if (sum == target) {
                len_l[hi] = len_r[lo] = hi - lo + 1;
            }
        }
        
        // Now converted to prefix_min.
        for (int i = 1; i < len_l.size(); i++) {
            len_l[i] = min(len_l[i], len_l[i - 1]);
        }
        for (int i = len_r.size() - 2; i >= 0 ; i--) {
            len_r[i] = min(len_r[i], len_r[i + 1]);
        }
        
        // Find the break point will provide minimum length.
        int res = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            res = min(res, len_l[i - 1] + len_r[i]);
        }
        return res >= INT_MAX >> 1 ? -1 : res;
    }
};

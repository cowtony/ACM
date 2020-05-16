// LeetCode 162: https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> &A) {
        int low = 0, high = A.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (A[mid] > A[mid - 1] and A[mid] > A[mid + 1]) {
                return mid;
            }
            if (A[mid] < A[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

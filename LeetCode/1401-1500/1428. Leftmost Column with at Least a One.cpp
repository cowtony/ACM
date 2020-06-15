/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> size = binaryMatrix.dimensions();
        
        int min_idx = INT_MAX;
        for (int r = 0; r < size[0]; r++) {
            int lo = 0, hi = size[1];
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (binaryMatrix.get(r, mid) == 0) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            if (hi < size[1]) {
                min_idx = min(min_idx, lo);
            }
        }
        
        return min_idx == INT_MAX? -1 : min_idx;
    }
};

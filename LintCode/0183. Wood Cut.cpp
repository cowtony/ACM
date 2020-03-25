class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        int small = 1, large = INT_MAX;
        int ans = 0;
        while (small <= large) {
            int mid = small + (large - small) / 2;
            int count = 0;
            for (int length : L) {
                count += length / mid;
            }
            if (count < k) {
                large = mid - 1;
            } else {
                ans = mid;
                small = mid + 1;
            }
        }
        return ans;
    }
};

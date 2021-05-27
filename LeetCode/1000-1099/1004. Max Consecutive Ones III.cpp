class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0;
        for (int hi = 0, lo = 0, zeros = 0; hi < A.size(); hi++) {
            if (A[hi] == 0) {
                zeros++;
            }
            if (zeros > K) {
                while (A[lo++] == 1);
                zeros--;
            }
            res = max(res, hi - lo + 1);
        }
        return res;
    }
};

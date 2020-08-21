class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        for (int lo = 0, hi = A.size() - 1; lo < hi; hi--) {
            if (A[hi] % 2 == 0) {
                swap(A[lo++], A[hi++]);
            }
        }
        
        return A;
    }
};

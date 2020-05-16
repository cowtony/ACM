class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> &A, vector<int> &B) {
        int length = A.size() + B.size();
        int k = length / 2;

        if (length % 2 == 0) {
            return (findKthNumber(A.begin(), A.end(), B.begin(), B.end(), k) + 
                    findKthNumber(A.begin(), A.end(), B.begin(), B.end(), k + 1)) / 2.0;
        } else {
            return findKthNumber(A.begin(), A.end(), B.begin(), B.end(), k + 1);
        }
    }
    
    int findKthNumber(const vector<int>::iterator& a_begin, 
                      const vector<int>::iterator& a_end, 
                      const vector<int>::iterator& b_begin, 
                      const vector<int>::iterator& b_end, 
                      int k) {
        if (a_begin == a_end) {
            return *(b_begin + k - 1);
        }
        if (b_begin == b_end) {
            return *(a_begin + k - 1);
        }
        if (k == 1) {
            return min(*a_begin, * b_begin);
        }
        
        int a_val = (a_end - a_begin < k / 2) ? INT_MAX : *(a_begin + k / 2 - 1);
        int b_val = (b_end - b_begin < k / 2) ? INT_MAX : *(b_begin + k / 2 - 1);
        
        if (a_val < b_val) {
            return findKthNumber(a_begin + k / 2, a_end, b_begin, b_end, k - k / 2);
        } else {
            return findKthNumber(a_begin, a_end, b_begin + k / 2, b_end, k - k / 2);
        }
    }
};

class Solution {
public:
    /*
     * @param A: sorted integer array A which has m elements, but size of A is m+n
     * @param m: An integer
     * @param B: sorted integer array B which has n elements
     * @param n: An integer
     * @return: nothing
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int pos = m + n - 1;
        m--;
        n--;
        while (pos >= 0) {
            if ((m < 0? INT_MIN : A[m]) > (n < 0? INT_MIN : B[n])) {
                A[pos] = A[m--];
            } else {
                A[pos] = B[n--];
            }
            pos--;
        }
    }
};

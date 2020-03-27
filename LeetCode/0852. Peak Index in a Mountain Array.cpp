class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 0, high = A.size() - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if ((mid == 0 or A[mid] > A[mid - 1]) and (mid == A.size() - 1 or A[mid] > A[mid + 1])) {
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

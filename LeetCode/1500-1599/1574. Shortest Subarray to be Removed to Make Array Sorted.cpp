class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int j;
        for (j = arr.size() - 1; j > 0; --j) {
            if (arr[j - 1] > arr[j]) {
                break;
            }
        }

        int result = j;  // Remove all 0 to j - 1 element.
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0 && arr[i] < arr[i - 1]) {
                break;
            }
            while (j < arr.size() && arr[j] < arr[i]) {
                j++;
            }
            if (i == j) {
                return 0;
            }
            result = min(result, j - i - 1);
        }
        return result;
    }
};

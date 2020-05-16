class Solution {
public:
    /**
     * @param array: the input array
     * @return: the sorted array
     */
    vector<vector<int>> multiSort(vector<vector<int>> &array) {
        sort(array.begin(), array.end(), 
        [](vector<int> a, vector<int> b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            } else {
                return a[1] > b[1];
            }
        });
        return array;
    }
};

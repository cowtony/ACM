class Solution {
public:
    /**
     * @param array: An given array.
     * @return: Return the number of "universal" subarrays.
     */
    int subarrays(vector<int> &array) {
        array.push_back(0);
        vector<int> counts;
        int count = 1;
        for (int i = 1; i < array.size(); i++) {
            if (array[i] == array[i - 1]) {
                count++;
            } else {
                counts.push_back(count);
                count = 1;
            }
        }
        
        int res = 0;
        for (int i = 1; i< counts.size(); i++) {
            res += min(counts[i], counts[i - 1]);
        }
        return res;
    }
};

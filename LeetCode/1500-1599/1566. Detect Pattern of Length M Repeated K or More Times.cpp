class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = m;
        for (int i = m; i < arr.size(); i++) {
            if (arr[i] == arr[i - m]) {
                if (++count >= m * k) {
                    return true;
                }
            } else {
                count = m;
            }
        }
        return false;
    }
};

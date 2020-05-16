class Solution {
public:
    /**
     * @param a: the array a
     * @return: return the index of median
     */
    int getAns(vector<int> &a) {
        vector<int> b = a;
        sort(a.begin(), a.end());
        int median = a[(a.size() + 1) / 2 - 1];
        for (int i = 0; i < a.size(); i++) {
            if (b[i] == median) {
                return i;
            }
        }
    }
};

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> res;
        for (int len = A.size(); len > 0; len--) {
            int max_idx = -1;
            int maximum = INT_MIN;
            for (int i = 0; i < len; i++) {
                if (A[i] > maximum) {
                    maximum = A[i];
                    max_idx = i;
                }
            }
            if (max_idx + 1 == len) {
                continue;
            }
            res.push_back(max_idx + 1);
            res.push_back(len);
            reverse(A.begin(), A.begin() + max_idx + 1);
            reverse(A.begin(), A.begin() + len);
        }
        return res;
    }
};

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (int l : left) {
            res = max(res, l);
        }
        for (int r : right) {
            res = max(res, n - r);
        }
        return res;
    }
};

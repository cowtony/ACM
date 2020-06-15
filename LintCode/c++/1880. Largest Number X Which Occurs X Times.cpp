class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: return the biggest value X, which occurs in A exactly X times.
     */
    int findX(vector<int> &arr) {
        unordered_map<int, int> count;
        for (int x : arr) {
            count[x]++;
        }
        
        int res = 0;
        for (auto p : count) {
            if (p.first == p.second) {
                res = max(res, p.first);
            }
        }
        return res;
    }
};

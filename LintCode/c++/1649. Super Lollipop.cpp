class Solution {
public:
    /**
     * @param v1: the speed of GGbond
     * @param v2: the speed of SuperQ
     * @param s: the speed that lollipop can add
     * @param w: the cost of lollipop
     * @return: the minimal price
     */
    int getAns(int v1, int v2, vector<int> &s, vector<int> &w) {
        if (v1 > v2) {
            return 0;
        }
        int speed_diff = v2 - v1;
        int min_cost = INT_MAX;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > speed_diff) {
                min_cost = min(min_cost, w[i]);
            }
        }
        return min_cost;
    }
};

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b) { swap(a, b); }
        if (b > c) { swap(b, c); }
        if (a > b) { swap(a, b); }

        if (c - a == 2) {
            return {0, c - a - 2};
        } else if (b - a <= 2 or c - b <= 2) {
            return {1, c - a - 2};
        } else {
            return {2, c - a - 2};
        }
    }
};

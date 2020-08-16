class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        N = (N - 1) % 14 + 1;
        while (N--) {
            vector<int> next(cells.size(), 0);
            for (int i = 1; i < cells.size() - 1; i++) {
                next[i] = !(cells[i - 1] ^ cells[i + 1]);
            }
            cells = next;
        }
        return cells;
    }
};

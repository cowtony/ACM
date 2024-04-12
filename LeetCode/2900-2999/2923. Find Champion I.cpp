class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            if (isChampion(grid[i], i)) {
                return i;
            }
        }
        return -1;
    }

    bool isChampion(const vector<int>& row, int team) {
        for (int i = 0; i < row.size(); i++) {
            if (i != team && row[i] == 0) {
                return false;
            }
        }
        return true;
    }
};

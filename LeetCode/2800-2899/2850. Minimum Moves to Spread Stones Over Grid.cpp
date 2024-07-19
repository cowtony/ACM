class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<int> empty;
        vector<int> extra;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    empty.push_back(hash(r, c));
                }
                while (grid[r][c] > 1) {
                    extra.push_back(hash(r, c));
                    grid[r][c]--;
                }
            }
        }

        dfs(extra, 0, empty);
        return result;
    }

    int hash(int r, int c) {
        return r * 3 + c;
    }

    void dfs(const vector<int>& extra, int depth, vector<int>& empty, int cost = 0) {
        if (depth == extra.size()) {
            result = min(result, cost);
            return;
        }

        for (int i = 0; i < empty.size(); i++) {
            if (empty[i] == -1) {
                continue;
            }
            int c = getCost(extra[depth], empty[i]);
            int tmp = empty[i];
            empty[i] = -1;
            dfs(extra, depth + 1, empty, cost + c);
            empty[i] = tmp;
        }
    }

    int getCost(int a, int b) {
        return abs(a / 3 - b / 3) + abs(a % 3 - b % 3);
    }

    int result = INT_MAX;
};

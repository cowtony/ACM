class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> safeness = getSafeness(grid);
        
        int low = 0, high = 800;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (canReach(safeness, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    vector<vector<int>> getSafeness(const vector<vector<int>>& grid) {
        vector<vector<int>> safeness(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    safeness[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            static const vector<int> kMove = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int rr = r + kMove[i];
                int cc = c + kMove[i + 1];

                if (rr >= 0 && rr < grid.size() && cc >= 0 && cc < grid[0].size() && safeness[rr][cc] == -1) {
                    safeness[rr][cc] = safeness[r][c] + 1;
                    q.push({rr, cc});
                }
            }
        }

        return safeness;
    }

    bool canReach(vector<vector<int>> safeness, int target) {
        if (safeness[0][0] < target) {
            return false;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == safeness.size() - 1 && c == safeness[0].size() - 1) {
                return true;
            }
            static const vector<int> kMove = {0, 1, 0, -1, 0};
            for (int i = 0; i < 4; i++) {
                int rr = r + kMove[i];
                int cc = c + kMove[i + 1];

                if (rr >= 0 && rr < safeness.size() && 
                    cc >= 0 && cc < safeness[0].size() && 
                    safeness[rr][cc] >= target) {
                    safeness[rr][cc] = -1;
                    q.push({rr, cc});
                }
            }
        }
        return false;
    }

};

class Solution {
public:
    struct State {
        int tail_row;
        int tail_col;
        int direction; // 0 = horizontal, 1 = vertical

        bool isInvalid() {
            return direction < 0;
        }
        bool isEnd(int m, int n) {
            return tail_row == m - 1 && tail_col == n - 2 && direction == 0;
        }
        void print() {
            cout << '(' << tail_row << ',' << tail_col << ") " << (direction == 0? "H" : "V") << endl;
        }
        vector<State> next(const vector<vector<int>>& grid) {
            vector<State> result;
            if (direction == 0) {
                // Move right
                if (tail_col + 2 < grid[0].size() && grid[tail_row][tail_col + 2] == 0) {
                    result.push_back({tail_row, tail_col + 1, direction});
                }
                // Move down && rotate
                if (tail_row + 1 < grid.size() &&
                    grid[tail_row + 1][tail_col] == 0 && grid[tail_row + 1][tail_col + 1] == 0) {
                    result.push_back({tail_row + 1, tail_col, direction});
                    result.push_back({tail_row, tail_col, 1 - direction});
                }
            } else {  // direction == 1
                // Move down
                if (tail_row + 2 < grid.size() && grid[tail_row + 2][tail_col] == 0) {
                    result.push_back({tail_row + 1, tail_col, direction});
                }
                // Move right && rotate
                if (tail_col + 1 < grid[0].size() &&
                    grid[tail_row][tail_col + 1] == 0 && grid[tail_row + 1][tail_col + 1] == 0) {
                    result.push_back({tail_row, tail_col + 1, direction});
                    result.push_back({tail_row, tail_col, 1 - direction});
                }
            }
            return result;
        }
    };

    int minimumMoves(vector<vector<int>>& grid) {
        queue<State> bfs;
        bfs.push(State{0, 0, 0});  // Initial state.
        bfs.push(State{-1, -1, -1});  // A invalid state for step identifier.
        int step = 0;
        vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(2, false)));
        while (!bfs.empty()) {
            auto state = bfs.front();
            bfs.pop();

            if (state.isInvalid()) {
                bfs.push(state);
                step++;
                if (bfs.front().isInvalid()) {
                    break;
                }
                continue;
            }
            if (state.isEnd(grid.size(), grid[0].size())) {
                return step;
            }
            for (const State& next : state.next(grid)) {
                if (!visited[next.tail_row][next.tail_col][next.direction]) {
                    bfs.push(next);
                    visited[next.tail_row][next.tail_col][next.direction] = true;
                }
            }
        }
        return -1;
    }
};

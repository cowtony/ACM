// Standard BFS using Queue, implementation with algorithm and model separation.
struct State {
    int row, col;

    static State invalidState() {
        return State{-1, -1};
    }
    bool isInvalid() const {
        return row == -1;
    }
    bool isEnd() const {
        return false;
    }
    vector<State> next(const vector<vector<int>>& grid) const {
        vector<State> result;
        if (row > 0) {
            result.push_back({row - 1, col});
        }
        if (row < grid.size() - 1) {
            result.push_back({row + 1, col});
        }
        if (col > 0) {
            result.push_back({row, col - 1});
        }
        if (col < grid[0].size() - 1) {
            result.push_back({row, col + 1});
        }
        return result;
    }
    bool visited(const vector<vector<int>>& grid) const {
        return grid[row][col] != 0;
    }
};

int BFS(...) {
    queue<State> bfs;
    bfs.push(State());  // Initial state.
    bfs.push(State::invalidState());  // A invalid state for step identifier.
    int step = 0;
    while (!bfs.empty()) {
        State state = bfs.front();
        bfs.pop();

        if (state.isInvalid()) {
            bfs.push(state);
            if (bfs.front().isInvalid()) {
                break;
            }
            step++;
            continue;
        }
        if (state.isEnd()) {
            return step;
        }
        for (const State& next : state.next(grid)) {
            if (!next.visited(grid)) {
                bfs.push(next);
                grid[next.row][next.col] = step;
            }
        }
    }
    return -1;
}

// When there is no way to create an invalid State as step identifier, other options are:
// - two queue swap
// - double while loop with temp queue

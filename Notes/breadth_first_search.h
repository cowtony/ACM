// Standard BFS using Queue, implementation with algorithm and model separation.
struct State {
    T data;

    static State invalidState() const;
    bool isInvalid() const;
    bool isEndState(...) const;
    vector<State> next(...) const;
};

int BFS(...) {
    queue<State> bfs;
    bfs.push(State());  // Initial state.
    bfs.push(State::invalidState());  // A invalid state for step identifier.
    int step = 0;
    unordered_set<State> visited;
    while (!bfs.empty()) {
        State state = bfs.front();
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
            if (!visited.find(next) != visited.end()) {
                bfs.push(next);
                visited.insert(next);
            }
        }
    }
    return -1;
}

// When there is no way to create an invalid State as step identifier, other options are:
// - two queue swap
// - double while loop with temp queue

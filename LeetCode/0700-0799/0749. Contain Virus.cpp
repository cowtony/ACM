class Cluster {
  public:
    Cluster(vector<vector<int>>& grid, int row, int col) {
        dfs(grid, row, col);
    }
    bool operator<(const Cluster& c) const {
        return expand.size() < c.expand.size();
    }
    void quarantine(vector<vector<int>>& grid) const {
        for (int p : points) {
            grid[p / grid[0].size()][p % grid[0].size()] = -1;
        }
    }
    void expansion(vector<vector<int>>& grid) const {
        for (int p : expand) {
            grid[p / grid[0].size()][p % grid[0].size()] = 1;
        }
    }
    int boundary = 0;
  private:
    vector<int> points;
    unordered_set<int> expand;
    
    void dfs(vector<vector<int>>& grid, int row, int col) {
        int hash = row * grid[0].size() + col;
        if (grid[row][col] == 0) {
            expand.insert(hash);
            boundary++;
        } else if (grid[row][col] == 1) {
            grid[row][col] = 2;
            points.push_back(hash);

            static const vector<int> kMove{0, 1, 0, -1, 0};
            for (int i = 0 ; i < 4; i++) {
                int r = row + kMove[i];
                int c = col + kMove[i + 1];
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) {
                    dfs(grid, r, c);
                }
            }
        }
    }
};

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int result = 0;
        while (true) {
            vector<Cluster> clusters;
            for (int row = 0; row < isInfected.size(); row++) {
                for (int col = 0; col < isInfected[0].size(); col++) {
                    if (isInfected[row][col] == 1) {
                        clusters.emplace_back(isInfected, row, col);
                    }
                }
            }
            if (clusters.empty()) {
                break;
            }
            sort(clusters.begin(), clusters.end());
            // Simulation:
            result += clusters.back().boundary;
            clusters.back().quarantine(isInfected);
            clusters.pop_back();
            for (const Cluster& cluster : clusters) {
                cluster.expansion(isInfected);
            }
            resetMarks(isInfected);  // Reset visited marks back to 1.
        }
        return result;
    }

    void resetMarks(vector<vector<int>>& grid) {
        for (auto& row : grid) {
            for (int& v : row) {
                if (v == 2) {
                    v = 1;
                }
            }
        }
    }

    void print(const vector<vector<int>>& grid) {
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] == -1) {
                    cout << "- ";
                } else {
                    cout << grid[row][col] << ' ';
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

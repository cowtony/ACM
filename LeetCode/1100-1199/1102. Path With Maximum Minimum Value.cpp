// Binary Search Answer + BFS
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int lo = 0, hi = 1E9;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (bfs(A, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    
    bool bfs(vector<vector<int>> A, int target) {
        if (A[0][0] < target) {
            return false;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            
            static const vector<int> kX = {0, 0, 1, -1};
            static const vector<int> kY = {1, -1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int r = pos.first + kX.at(i);
                int c = pos.second + kY.at(i);
                
                if (r < 0 or r >= A.size() or c < 0 or c >= A[0].size()) {
                    continue;
                }
                if (A[r][c] >= target) {
                    A[r][c] = -1;  // visited.
                    if (r == A.size() - 1 and c == A[0].size() - 1) {
                        return true;
                    }
                    q.push({r, c});
                }
            }
        }
        return false;
    }
};

// Sort + Union Find.
class UnionFind {
public:
    UnionFind(int n) : father(n) {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        count = n;
    }
    void connect(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra != rb) {
            father[ra] = rb;
            count--;
        }
    }
    int root(int a) {
        if (father[a] == a) { return a; } 
        else { return father[a] = root(father[a]); }
    }
    
    int count;
private:
    vector<int> father;
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<tuple<int, int, int>> cells;
        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[0].size(); c++) {
                cells.push_back({A[r][c], r, c});
            }
        }
        sort(cells.begin(), cells.end(), greater<tuple<int, int, int>>());
        
        UnionFind uf(A.size() * A[0].size());
        const vector<int> kX = {0, 0, 1, -1};
        const vector<int> kY = {1, -1, 0, 0};
        for (auto [score, row, col] : cells) {
            uf.root(row * A[0].size() + col);
            A[row][col] = -1;
            
            for (int i = 0; i < 4; i++) {
                int r = row + kX.at(i);
                int c = col + kY.at(i);
                if (r < 0 or r >= A.size() or c < 0 or c >= A[0].size()) {
                    continue;
                }
                if (A[r][c] == -1) {
                    uf.connect(r * A[0].size() + c, row * A[0].size() + col);
                }
            }
            
            if (uf.root(0) == uf.root(A.size() * A[0].size() - 1)) {
                return score;
            }
        }
        
        return 0;
    }
};

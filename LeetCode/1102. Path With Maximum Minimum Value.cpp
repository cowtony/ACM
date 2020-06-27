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

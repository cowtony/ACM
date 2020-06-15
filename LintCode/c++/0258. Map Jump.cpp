class Solution {
public:
    /**
     * @param arr: the map
     * @return:  the smallest target that satisfies from the upper left corner (0, 0) to the lower right corner (n-1, n-1)
     */
    int mapJump(vector<vector<int>> &arr) {
        int lo = 0, hi = 1000;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (BFS(arr, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    
    const vector<int> kX = {0, 0, 1, -1};
    const vector<int> kY = {1, -1, 0, 0};
    bool BFS(const vector<vector<int>> &arr, int target) {
        vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            q.pop();
            
            if (pos.first == arr.size() - 1 and pos.second == arr[0].size() - 1) {
                return true;
            }
            for (int i = 0; i < 4; i++) {
                int r = pos.first + kX.at(i);
                int c = pos.second + kY.at(i);
                if (r < 0 or r >= arr.size() or c < 0 or c >= arr[0].size()) {
                    continue;
                }
                if (abs(arr[r][c] - arr[pos.first][pos.second]) > target) {
                    continue;
                }
                if (!visited[r][c]) {
                    visited[r][c] = true;
                    q.push(make_pair(r, c));
                }
            }
        }
        return false;
    }
};

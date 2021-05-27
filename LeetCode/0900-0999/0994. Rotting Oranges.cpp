class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_orange = 0;
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                } else if (grid[r][c] == 1) {
                    fresh_orange++;
                }
            }
        }
        
        
        const vector<int> kX = {0, 0, 1, -1};
        const vector<int> kY = {1, -1, 0, 0};
        
        int minute = 0;
        const pair<int, int> kDel(-1, -1);
        q.push(kDel); // To identify layer.
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            if (p == kDel) {
                q.push(kDel);
                if (q.front() == kDel) {
                    break;
                }
                minute++;
                continue;
            }
            
            for (int i = 0; i < 4; i++) {
                int r = p.first + kX.at(i);
                int c = p.second + kY.at(i);
                
                if (r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size()) {
                    continue;
                }
                if (grid[r][c] == 1) {
                    grid[r][c] = 2;
                    fresh_orange--;
                    q.push({r, c});
                }
            }
        }
        
        return fresh_orange == 0? minute : -1;
    }
};

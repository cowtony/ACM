class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {        
        const vector<int> kX{0, 0, 1, -1};
        const vector<int> kY{1, -1, 0, 0};
        
        queue<vector<int>> q;
        q.push(start);
        while (!q.empty()) {
            auto point = q.front();
            q.pop();

            if (point == destination) {
                return true;
            }
            
            for (int dir = 0; dir < 4; dir++) {
                int r = point[0];
                int c = point[1];
                while (true) {
                    r += kX.at(dir);
                    c += kY.at(dir);
                    if (r < 0 or r >= maze.size() or c < 0 or c >= maze[0].size() or maze[r][c] > 0) {
                        r -= kX.at(dir);
                        c -= kY.at(dir);
                        if (maze[r][c] == 0) {
                            maze[r][c] = -1; // Visited.
                            q.push({r, c});
                        }
                        break;
                    }
                }
            }
        } 
        return false;
    }
};

struct Node {
    int r;
    int c;
    int step = 0;
    bool operator< (const Node& n) const {
        if (r == n.r) {
            return c < n.c;
        }
        return r < n.r;
    }
};

class Solution {
public:
    /**
     * @param mazeMap: a 2D grid
     * @return: return the minium distance
     */
    int getMinDistance(vector<vector<int>> &mazeMap) {
        unordered_map<int, set<Node>> jump;
        Node start, end;
        for (int r = 0; r < mazeMap.size(); r++) {
            for (int c = 0; c < mazeMap[0].size(); c++) {
                if (mazeMap[r][c] == -2) {
                    start = {r, c};
                } else if (mazeMap[r][c] == -3) {
                    end = {r, c};
                } else if (mazeMap[r][c] > 0) {
                    jump[mazeMap[r][c]].insert({r, c});
                }
            }
        }
        
        
        const vector<int> kX = {0, 0, 1, -1};
        const vector<int> kY = {1, -1, 0, 0};
        queue<Node> q;
        q.push(start);
        while (!q.empty()) {
            Node n = q.front();
            q.pop();
            // cout << n.r << ' ' << n.c << endl;
            
            for (const Node& next : jump[mazeMap[n.r][n.c]]) {
                q.push({next.r, next.c, n.step + 1});
                jump[mazeMap[n.r][n.c]].erase(next);
            }
            
            for (int i = 0; i < 4; i++) {
                int r = n.r + kX.at(i);
                int c = n.c + kY.at(i);
                if (r < 0 or r >= mazeMap.size() or c < 0 or c >= mazeMap[0].size()) {
                    continue;
                }
                if (mazeMap[r][c] == -3) {
                    return n.step + 1;
                }
                if (mazeMap[r][c] < 0) {
                    continue;
                }
                if (mazeMap[r][c] == 0) {
                    q.push({r, c, n.step + 1});
                    mazeMap[r][c] = -1;
                } else if (jump[mazeMap[r][c]].find({r, c}) != jump[mazeMap[r][c]].end()) {
                    q.push({r, c, n.step + 1});
                    jump[mazeMap[r][c]].erase({r, c});
                }
                
            }
        }
        
        return -1;
    }
};

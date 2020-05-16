class Solution {
public:
    /**
     * @param map: the map
     * @return: can you reach the endpoint
     */
    bool reachEndpoint(vector<vector<int>> &map) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        
        vector<int> x = {0, 0, 1, -1};
        vector<int> y = {1, -1, 0, 0};
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int r = p.first + x[i];
                int c = p.second + y[i];
                
                if (r < 0 or r >= map.size() or c < 0 or c >= map[0].size()) {
                    continue;
                }
                if (map[r][c] == 1) {
                    map[r][c] = 0;
                    q.push({r, c});
                } else if (map[r][c] == 9) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

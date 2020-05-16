class Solution {
public:
    /**
     * @param Mine_map: an array represents the map.
     * @param Start: the start position.
     * @return: return an array including all reachable positions.
     */
    vector<vector<int>> Mine_sweeping(vector<vector<int>> &Mine_map, vector<int> &Start) {
        dfs(Mine_map, Start[0], Start[1]);
        return {ret.begin(), ret.end()};
    }
    
    set<vector<int>> ret;
    const vector<int> x = {0, 0, 1, -1};
    const vector<int> y = {1, -1, 0, 0};
    
    void dfs(vector<vector<int>> &Mine_map, int i, int j) {
        ret.insert({i, j});
        if (Mine_map[i][j] == 0) {
            return;
        }
        Mine_map[i][j] = 0;
        
        for (int k = 0; k < 4; k++) {
            int r = i + x[k];
            int c = j + y[k];
            
            if (r < 0 or r >= Mine_map.size()) {
                continue;
            }
            if (c < 0 or c >= Mine_map[0].size()) {
                continue;
            }
            dfs(Mine_map, r, c);
        }
    }
};

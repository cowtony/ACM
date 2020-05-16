class Solution {
public:
    /**
     * @param colors: the colors of grids
     * @return: return the minimum step from position 0 to position n - 1
     */
    int minimumStep(vector<int> &colors) {
        vector<vector<int>> color_map(colors.size() + 1);
        for (int i = 0; i < colors.size(); i++) {
            color_map[colors[i]].emplace_back(i);
        }
        vector<bool> visited(colors.size(), false);
        visited[0] = true;
        
        queue<int> q;
        q.push(0);
        q.push(-1);
        
        int step_count = 0;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            
            if (idx == -1) {
                step_count++;
                q.push(-1);
                if (q.front() == -1) {
                    break;
                }
                continue;
            }
            if (idx == colors.size() - 1) {
                return step_count;
            }
            for (int i : color_map.at(colors.at(idx))) {
                if (!visited[i]) {
                    if (i == colors.size() - 1) {
                        return step_count + 1;
                    }
                    q.push(i);
                    visited[i] = true;
                }
            }
            
            if (idx > 0 and !visited[idx - 1]) {
                if (idx - 1 == colors.size() - 1) {
                    return step_count + 1;
                }
                q.push(idx - 1);
                visited[idx - 1] = true;
            }
            if (idx < colors.size() - 1 and !visited[idx + 1]) {
                if (idx + 1 == colors.size() - 1) {
                    return step_count + 1;
                }
                q.push(idx + 1);
                visited[idx + 1] = true;
            }
            
        }
        return -1;
    }
};

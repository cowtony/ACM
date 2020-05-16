class Solution {
public:
    /**
     * @param n: An integer
     * @param str: a string with number from 1-n in random order and miss one number
     * @return: An integer
     */
    int findMissing2(int n, string &str) {
        vector<bool> visited(n + 1, false);
        return dfs(visited, str);
    }
    
    int dfs(vector<bool>& visited, string s, vector<int> path = {}) {
        if (s.empty()) {
            vector<int> unvisited;
            for (int i = 1; i < visited.size(); i++) {
                if (!visited[i]) {
                    unvisited.push_back(i);
                }
            }
            if (unvisited.size() == 1) {
                return unvisited[0];
            } else {
                return 0;
            }
        }
        int num = 0;
        while (!s.empty()) {
            num = num * 10 + (s[0] - '0');
            s = s.substr(1);
            if (num == 0 or num >= visited.size()) {
                break;
            }
            if (!visited[num]) {
                visited[num] = true;
                path.push_back(num);
                int res = dfs(visited, s, path);
                if (res > 0) {
                    return res;
                }
                visited[num] = false;
                path.pop_back();
            }
        }
        return 0;
    }
};

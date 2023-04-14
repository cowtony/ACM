class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (const auto& path : paths) {
            graph[path[0] - 1].push_back(path[1] - 1);
            graph[path[1] - 1].push_back(path[0] - 1);
        }

        vector<int> flower_type(n, 0);
        for (int i = 0; i < n; ++i) {
            vector<bool> colors(5, false);
            for (int neighbor : graph[i]) {
                colors[flower_type[neighbor]] = true;
            }
            for (int c = 1; c <= 4; ++c) {
                if (!colors[c]) {
                    flower_type[i] = c;
                    break;
                }
            }
        }
        return flower_type;
    }
};

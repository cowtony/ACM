class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(graph, 0, path);
        return res;
    }
    
    vector<vector<int>> res;
    void dfs(const vector<vector<int>>& graph, int vertex, vector<int>& path) {
        path.push_back(vertex);
        if (graph[vertex].empty()) {
            res.push_back(path);
        } else {
            for (int next : graph[vertex]) {
                dfs(graph, next, path);
            }
        }
        path.pop_back();
    }
};

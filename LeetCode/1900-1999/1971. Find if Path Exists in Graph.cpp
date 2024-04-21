class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> bfs;
        bfs.push(source);
        visited[source] = true;
        while (!bfs.empty()) {
            int node = bfs.front();
            if (node == destination) {
                return true;
            }
            bfs.pop();

            for (int next : graph[node]) {
                if (!visited[next]) {
                    visited[next] = true;
                    bfs.push(next);
                }
            }
        }
        return false;
    }
};

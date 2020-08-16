class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<unordered_map<int, vector<int>>> edges(2);
        for (const auto& edge : red_edges) {
            edges[0][edge[0]].emplace_back(edge[1]);
        }
        unordered_map<int, vector<int>> b_edges;
        for (const auto& edge : blue_edges) {
            edges[1][edge[0]].emplace_back(edge[1]);
        }
        
        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        dist[0][0] = dist[1][0] = 0;
        
        queue<tuple<int, int, int>> q; // Vertex, distance, Red or Blue
        q.push({0, 0, 0});
        q.push({0, 0, 1});
        while (!q.empty()) {
            int vertex, distance, red;
            tie(vertex, distance, red) = q.front();
            q.pop();
            
            red = 1 - red;
            
            for (int next : edges[red][vertex]) {
                if (dist[red][next] != INT_MAX) {
                    continue;
                }
                dist[red][next] = distance + 1;
                q.push({next, distance + 1, red});
            }
        }
        
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = min(dist[0][i], dist[1][i]);
            if (res[i] == INT_MAX) {
                res[i] = -1;
            }
        }
        return res;
    }
};

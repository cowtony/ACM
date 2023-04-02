class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int result = INT_MAX;
        for (int node = 0; node < n; node++) {
            vector<int> distance(n, INT_MAX);
            distance[node] = 0;
            vector<int> parent(n, -1);
            
            queue<int> q;
            q.push(node);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int next : graph[v]) {
                    if (distance[next] == INT_MAX) {
                        distance[next] = distance[v] + 1;
                        parent[next] = v;
                        q.push(next);
                    } else if (parent[next] != v && parent[v] != next) {
                        result = min(result, distance[v] + distance[next] + 1);
                    }
                }
            }
        }
        
        return result == INT_MAX? -1 : result;
    }
};

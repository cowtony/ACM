class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build graph.
        vector<vector<int>> graph(n);
        for(vector<int>& edge : connections) {
            graph[edge[0]].emplace_back(edge[1]); 
            graph[edge[1]].emplace_back(edge[0]); 
        }

        // Similar to an array to memorize min_distance, but this one define all distance for a cycle will be the same.
        vector<int> order(n, -1);  
        dfs(graph, order, 0); 
        return res; 
    }

    vector<vector<int>> res; 
    void dfs(const vector<vector<int>>& graph, vector<int>& order, 
             int vertex, int depth = 0, int parent = -1) {
        order[vertex] = depth;
        for(int next : graph.at(vertex)) {
            if (next == parent) {
                continue; // Prevent go back directly.
            }
            if (order[next] == -1) { // not visited
                dfs(graph, order, next, depth + 1, vertex);
                if (order[next] > depth) {
                    res.push_back({vertex, next}); // this must be a bridge 
                }
            }
            // calc The earliest point that can be reached by a non-father node
            order[vertex] = min(order[vertex], order[next]);    
        }
    }
};

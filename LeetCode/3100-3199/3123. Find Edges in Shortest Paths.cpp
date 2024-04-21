class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, long>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<long> dist_0 = dijkstra(graph, 0);
        vector<long> dist_n = dijkstra(graph, n - 1);
        
        long min_dist = dist_0[n - 1];
        vector<bool> result;
        result.reserve(edges.size());
        for (const auto& edge : edges) {
            result.push_back(dist_0[edge[0]] + dist_n[edge[1]] + edge[2] == min_dist || 
                             dist_0[edge[1]] + dist_n[edge[0]] + edge[2] == min_dist);
        }
        return result;
    }
    
    vector<long> dijkstra(const vector<vector<pair<int, long>>>& graph, int from_vertex) {
        vector<long> distance(graph.size(), INT_MAX);
        distance[from_vertex] = 0;
        vector<bool> visited(graph.size(), false);
        
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, from_vertex});
        while (!pq.empty()) {
            int vertex = pq.top().second;
            pq.pop();
            if (visited[vertex]) {
                continue;
            }
            visited[vertex] = true;
            
            for (const auto& [node, weight] : graph[vertex]) {
                if (distance[vertex] != INT_MAX && distance[node] > distance[vertex] + weight) {
                    distance[node] = distance[vertex] + weight;
                    pq.push({distance[node], node});
                }
            }
        }
        return distance;
    }
};

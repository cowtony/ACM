class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, long>>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        return dijkstra(graph, disappear);
    }

    vector<int> dijkstra(const vector<vector<pair<int, long>>>& graph, const vector<int>& disappear, int from_vertex = 0) {
        vector<int> distance(graph.size(), -1);
        distance[from_vertex] = 0;
        
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
        pq.push({0, from_vertex});  
        while (!pq.empty()) {
            auto [t, vertex] = pq.top();
            pq.pop();

            if (t != distance[vertex]) {
                continue;
            }

            for (const auto& [node, weight] : graph[vertex]) {
                if (t + weight < disappear[node] && (distance[node] == -1 || distance[node] > distance[vertex] + weight)) {
                    distance[node] = distance[vertex] + weight;
                    pq.emplace(distance[node], node);
                }
            }
        }
        return distance;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].emplace_back(-log(succProb[i]), edges[i][1]);
            graph[edges[i][1]].emplace_back(-log(succProb[i]), edges[i][0]);  // < 0
        }
        
        auto dist = dijkstra(graph, start, end, n);
        if (dist[end] == 1e10) {
            return 0.0;
        } else {
            return pow(2.7182818284590452353602874713527, -dist[end]);
        }
        
        
    }
    
    template<class V, class W>
    vector<W> dijkstra(const vector<vector<pair<W, V>>>& edges, int from, int to, int n) {
        vector<W> distance(n, 1e10);
        distance[from] = 0;
        vector<V> previous(n);

        priority_queue<pair<W, V>, vector<pair<W, V>>, greater<pair<W, V>>> pq;
        pq.push({0, from});
        while (!pq.empty()) {
            int next = pq.top().second;
            pq.pop();

            for (const auto& edge : edges.at(next)) {
                if (distance[edge.second] == 1e10 or distance[edge.second] > distance[next] + edge.first) {
                    distance[edge.second] = distance[next] + edge.first;
                    pq.push(edge);
                }
            }
        }
        return distance;
    }
};

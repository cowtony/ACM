class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int, int>>> edges;
        for (const auto& edge : times) {
            edges[edge[0]].emplace_back(edge[2], edge[1]);
        }
        
        auto distances = dijkstra(edges, K);
        
        int res = 0;
        for (int i = 1; i <= N; i++) {
            if (distances.find(i) == distances.end()) {
                return -1;
            }
            res = max(res, distances[i]);
        }
        return res;
    }
    
    template<class V, class W>
    unordered_map<V, W> dijkstra(const unordered_map<V, vector<pair<W, V>>>& edges, int from) {
        unordered_map<V, W> distance;
        distance[from] = 0;
        unordered_map<V, V> previous;
        
        priority_queue<pair<W, V>, vector<pair<W, V>>, greater<pair<W, V>>> pq;
        pq.push({0, from});
        while (!pq.empty()) {
            int next = pq.top().second;
            pq.pop();
            
            if (edges.find(next) == edges.end()) {
                continue;
            }
            for (const auto& edge : edges.at(next)) {
                if (distance.find(edge.second) == distance.end() or distance[edge.second] > distance[next] + edge.first) {
                    distance[edge.second] = distance[next] + edge.first;
                    pq.push(edge);
                }
            }
        }
        return distance;
    }
};

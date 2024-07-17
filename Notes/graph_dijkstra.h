// Dijkstra O((E+V) log(V))
// For node from 0 to n:
vector<long> dijkstra(const vector<vector<pair<int, long>>>& graph, int from_vertex = 0) {
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

        if (edges.find(next) == edges.end() or distance.find(next) == distance.end()) {
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

// For node from 0 to n:
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

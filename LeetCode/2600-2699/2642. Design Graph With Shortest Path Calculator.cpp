class Graph {
public:
    Graph(int n, vector<vector<int>>& edges): kInf(INT_MAX / 3), dist(n, vector<int>(n, kInf)) {
        for (int i = 0; i < n ; i++) {
            dist[i][i] = 0;
        }
        for (const auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
        }
        // Floyd
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(const vector<int>& edge) {
        int n = dist.size();
        dist[edge[0]][edge[1]] = min(dist[edge[0]][edge[1]], edge[2]);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][edge[0]] + edge[2] + dist[edge[1]][j]);
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] == kInf? -1 : dist[node1][node2];
    }
    
  private:
    const int kInf;
    vector<vector<int>> dist;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

// hash map / set
template<class Node = int>
class TopologicalSort {
  public:
    void addNode(Node n) { indegree[n]; }
    
    void addEdge(Node from, Node to) {
        if (graph[from].find(to) == graph[from].end()) {
            ++indegree[to];
            graph[from].insert(to);
        }
    }
    // Return the node and it's rank <node, rank>
    vector<pair<Node, int>> sort() {
        vector<pair<Node, int>> result;
        queue<pair<Node, int>> q;
        for (const auto& [node, val] : indegree) {
            if (val == 0) {
                q.push({node, 0});
            }
        }
        while (!q.empty()) {
            auto [node, rank] = q.front();
            q.pop();
            result.push_back({node, rank});
            for (const Node& next : graph[node]) {
                if (--indegree[next] == 0) {
                    q.push({next, rank + 1});
                }
            }
        }
        if (result.size() != indegree.size()) {
            return {};
        }
        return result;
    }
  private:
    unordered_map<Node, int> indegree;
    unordered_map<Node, unordered_set<Node>> graph;
};

// Vector
class TopologicalSort {
public:
    TopologicalSort(int n) : indegree(n, 0), graph(n) {}
    
    void addEdge(int from, int to) {
        if (graph[from].find(to) == graph[from].end()) {
            indegree[to]++;
            graph[from].insert(to);
        }
    }
    
    vector<int> tpologicalSort() {
        vector<int> res;
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int next : graph[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return res.size() != indegree.size()? {} : res;
    }

    vector<int> indegree;
    vector<unordered_set<int>> graph;
};

// Unordered_map.
template<class T = int>
class TopologicalSort {
public:
    void addNode(T n) { indegree[n]; }
    
    void addEdge(T from, T to) {
        if (graph[from].find(to) == graph[from].end()) {
            ++indegree[to];
            graph[from].insert(to);
        }
    }
    
    vector<T> tpologicalSort() {
        vector<T> res;
        queue<T> q;
        for (auto p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }
        while (!q.empty()) {
            T node = q.front();
            q.pop();
            res.push_back(node);
            for (T next : graph[node]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return res.size() != indegree.size()? vector<T>() : res;
    }
private:
    unordered_map<T, int> indegree;
    unordered_map<T, unordered_set<T>> graph;
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

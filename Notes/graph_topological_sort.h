template<class T>
class TopologicalSort {
public:
    void addNode(T n) { indegree[n]; }
    
    void addEdge(T from, T to) {
        if (graph.find(from) != graph.end() and 
            graph.at(from).find(to) != graph.at(from).end()) {
            return;
        }
        indegree[to]++;
        graph[from].insert(to);
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
                indegree[next]--;
                if (indegree[next] == 0) {
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

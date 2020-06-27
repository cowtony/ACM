class TopologicalSort {
public:
    TopologicalSort(int n) : indegree(n, 0), graph(n) {}
    
    void addEdge(int from, int to) {
        if (graph[from].find(to) == graph[from].end()) {
            indegree[to]++;
            graph[from].insert(to);
        }
    }

    vector<int> indegree;
    vector<unordered_set<int>> graph;
};

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        TopologicalSort ts(n);
        for (auto& edge : dependencies) {
            ts.addEdge(edge[0] - 1, edge[1] - 1);
        }
        
        vector<int> depth(n, -1);
        for (int i = 0; i < n ; i++) {
            dfs_depth(depth, ts.graph, i);
        }
        
        int term = 0, took = 0;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < ts.indegree.size(); i++) {
            if (ts.indegree[i] == 0) {
                pq.push({depth[i], i});
                ts.indegree[i] = -1;
            }
        }
        while (took < n) {
            int count = 0;
            vector<pair<int, int>> next_queue;
            while (!pq.empty() and count++ < k) {
                auto p = pq.top();
                pq.pop();
                for (int next : ts.graph[p.second]) {
                    if (--ts.indegree[next] == 0) {
                        next_queue.push_back({depth[next], next});
                    }
                }
                took++;
            }
            for (auto p : next_queue) {
                pq.push(p);
            }
            term++;
        }
        
        return term;
    }
    
    int dfs_depth(vector<int>& depth, const vector<unordered_set<int>>& graph, int i) {
        if (depth[i] >= 0) {
            return depth[i];
        }
        int d = 0;
        for (int next : graph[i]) {
            d = max(d, dfs_depth(depth, graph, next) + 1);
        }
        return depth[i] = d;
    }
};

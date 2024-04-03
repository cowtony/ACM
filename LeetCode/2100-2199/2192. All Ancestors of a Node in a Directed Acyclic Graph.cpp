class TopologicalSort {
  public:
    TopologicalSort(int n) : indegree(n, 0), children(n) {}
    
    void addEdge(const int& from, const int& to) {
        if (children[from].find(to) == children[from].end()) {
            indegree[to]++;
            children[from].insert(to);
        }
    }
    
    vector<set<int>> sort() {
        vector<set<int>> ancestors(indegree.size());
        queue<int> q;

        // Find all ancestors.
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int next : children[node]) {
                ancestors[next].insert(node);
                ancestors[next].insert(ancestors[node].begin(), ancestors[node].end());
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        return ancestors;
    }

  private:
    vector<int> indegree;
    vector<unordered_set<int>> children;
};

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        TopologicalSort ts(n);
        for (const auto& edge : edges) {
            ts.addEdge(edge[0], edge[1]);
        }

        vector<vector<int>> result;
        result.reserve(n);
        for (const set<int>& a : ts.sort()) {
            result.emplace_back(vector<int>(a.begin(), a.end()));
        }
        
        return result;
    }
};

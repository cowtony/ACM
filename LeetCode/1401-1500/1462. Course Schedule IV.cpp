class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> graph(n);
        for (auto p : prerequisites) {
            graph[p[0]].insert(p[1]);
        }
        
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            dfs(graph, visited, i);
        }
        
        vector<bool> res;
        for (auto query : queries) {
            res.push_back(graph[query[0]].find(query[1]) != graph[query[0]].end());
        }
        return res;
    }
    
    void dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, int idx) {
        if (visited[idx]) {
            return;
        }
        
        unordered_set<int> res = graph[idx];
        for (int next : graph[idx]) {
            dfs(graph, visited, next);
            res.insert(graph[next].begin(), graph[next].end());
        }
        graph[idx] = res;
        visited[idx] = true;
    }
};

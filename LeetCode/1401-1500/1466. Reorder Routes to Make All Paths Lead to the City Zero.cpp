class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<unordered_set<int>> undirect_graph(n);
        vector<unordered_set<int>> direct_graph(n);
        for (auto& c : connections) {
            undirect_graph[c[0]].insert(c[1]);
            undirect_graph[c[1]].insert(c[0]);
            direct_graph[c[0]].insert(c[1]);
        }
        
        vector<bool> visited(n, false);
        int res = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            
            for (int next : undirect_graph[node]) {
                if (visited[next] == false) {
                    q.push(next);
                    if (direct_graph[node].find(next) != direct_graph[node].end()) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        } else if (n == 2) {
            return {0, 1};
        }
        
        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            int v1 = edge[0], v2 = edge[1];
            graph[v1].insert(v2);
            graph[v2].insert(v1);
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }
        q.push(-1);

        int remain = n;
        while (true) {
            int node = q.front();
            q.pop();

            if (node == -1) {
                if (remain <= 2) {
                    break;
                }
                q.push(-1);
                continue;
            }

            remain--;

            int next = *graph[node].begin();
            graph[node].erase(next);
            graph[next].erase(node);

            if (graph[next].size() == 1) {
                q.push(next);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

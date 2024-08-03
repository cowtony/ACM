class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        const int N = edges.size() + 1;
        
        vector<vector<int>> graph(N);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Init with node 0
        vector<int> subtree_max(N, 0);
        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            for (int child : graph[node]) {
                if (child != parent) {
                    subtree_max[node] = max(subtree_max[node], dfs(child, node) + 2 - child % 2);
                }
            }
            return subtree_max[node];
        };
        dfs(0, -1);
        
        // re-rooting
        vector<int> result(N);
        function<void(int, int, int)> reroot = [&](int node, int parent, int parent_contrib) {
            vector<int> max_value(2, 0);
            if (parent != -1) {
                push(max_value, parent_contrib + 2 - parent % 2);
            }
            for (int child : graph[node]) {
                if (child != parent) {
                    push(max_value, subtree_max[child] + 2 - child % 2);
                }
            }
            result[node] = max_value[0];  // Assign the largest value.

            for (int child : graph[node]) {
                if (child != parent) {
                    reroot(child, node, subtree_max[child] + 2 - child % 2 == max_value[0]? max_value[1] : max_value[0]);
                }
            }
        };
        reroot(0, -1, 0);
        
        return result;
    }

    void push(vector<int>& v, int val) {
        if (val > v[1]) {
            v[1] = val;
        }
        if (v[1] > v[0]) {
            swap(v[1], v[0]);
        }
    };
    
};

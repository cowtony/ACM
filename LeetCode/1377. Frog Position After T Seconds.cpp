class Solution {
public:
    vector<vector<double>> p;
    vector<vector<bool>> graph;
    vector<bool> visited;
    map<int, set<int>> map_g;
    int N, T;
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        p = vector<vector<double>>(t + 1, vector<double>(n + 1, 0.0));
        graph = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
        visited = vector<bool>(n + 1, false);
        p[0][1] = 1.0;
        visited[1] = true;
        N = n;
        T = t;
        
        for (vector<int> edge : edges) {
            graph[edge[0]][edge[1]] = true;
            graph[edge[1]][edge[0]] = true;
            map_g[edge[0]].emplace(edge[1]);
            map_g[edge[1]].emplace(edge[0]);
        }
        
        dfs(1, 0);
        
        return p[t][target];
    }
    
    void dfs(int node, int current_t) {
        if (current_t == T) {
            return;
        }
        
        if (p[current_t][node] == 0) {
            return;
        }

        set<int> next;
        for (int i : map_g[node]) {
            if (!visited[i]) {
                next.insert(i);
            }
        }
        
        if (next.empty()) {
            p[current_t + 1][node] += p[current_t][node];
            dfs(node, current_t + 1);
        } else {
            double p_next = p[current_t][node] / next.size();
            for (int k : next) {
                p[current_t + 1][k] += p_next;
                visited[k] = true;
                dfs(k, current_t + 1);
                visited[k] = false;
            }
        }
    }
};

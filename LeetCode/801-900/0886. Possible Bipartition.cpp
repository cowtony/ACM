class Solution {
public:
    // Bipartite graph
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, unordered_set<int>> graph;
        for (const vector<int>& dislike : dislikes) {
            graph[dislike.at(0)].insert(dislike.at(1));
            graph[dislike.at(1)].insert(dislike.at(0));
        }
        
        vector<int> color(N + 1, 0); // 0: unvisited, 1 or -1: colored
        for (int i = 1; i <= N; i++) {
            if (color[i] != 0) {
                continue;
            }
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int n = q.front();
                q.pop();
                for (int next : graph[n]) {
                    if (color[next] == 0) {
                        q.push(next);
                        color[next] = -color[n];
                    } else if (color[next] == color[n]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

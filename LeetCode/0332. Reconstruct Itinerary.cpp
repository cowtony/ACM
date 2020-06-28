class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> graph;
        for (const auto& ticket : tickets) {
            graph[ticket[0]][ticket[1]]++;
        }
        
        dfs(graph, "JFK", tickets.size() + 1);
        return res;
    }
    
    vector<string> res;
    bool dfs(unordered_map<string, map<string, int>>& graph, const string& start, int size) {
        res.push_back(start);
        if (res.size() == size) {
            return true;
        }

        for (auto& next : graph[start]) {
            if (graph[start][next.first] > 0) {
                graph[start][next.first]--;
                if (dfs(graph, next.first, size)) {
                    return true;
                }
                graph[start][next.first]++;
            }
        }
        res.pop_back();
        return false;
    }
};

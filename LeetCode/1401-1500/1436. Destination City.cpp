class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> graph;
        for (auto& path : paths) {
            graph[path[0]] = path[1];
        }
        string city = paths.front().front();
        while (true) {
            if (graph.find(city) == graph.end()) {
                return city;
            } else {
                city = graph.at(city);
            }
        }
        return "";
    }
};

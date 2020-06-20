class Solution {
public:
    /**
     * @param commands: the commands of this program.
     * @return: return is the program may be in endless loop.
     */
    bool check(vector<string> &commands) {
        unordered_map<string, int> label_map;
        for (int i = 0; i < commands.size(); i++) {
            auto s = split(commands[i], " ");
            if (s.front() == "label") {
                label_map[s.back()] = i;
            }
        }
        
        vector<vector<int>> graph(commands.size());
        for (int i = 0; i < commands.size(); i++) {
            auto s = split(commands[i], " ");
            if (s.front() == "label" or s.front() == "print") {
                graph[i].push_back(i + 1);
            } else if (s.front() == "halt") {
                graph[i].push_back(commands.size());
            } else if (s.front() == "goto" or s.front() == "gotorand") {
                for (int j = 1; j < s.size(); j++) {
                    graph[i].push_back(label_map[s[j]]);
                }
            }
        }
        
        vector<bool> visited(commands.size(), false);
        return hasCycle(graph, visited, 0);
    }
    
    vector<string> split(string s, string delimiter) {
        vector<string> res;
        size_t p = 0;
        while (p <= s.length()) {
            size_t pos = s.find(delimiter, p);
            if (pos == string::npos) {
                pos = s.length();
            }
            res.emplace_back(s.substr(p, pos - p));
            p = pos + delimiter.length();
        }
        return res;
    }
    
    bool hasCycle(const vector<vector<int>>& adjacency_list, vector<bool>& visited, int node) {
        if (node < 0 or node >= visited.size()) {
            return false;
        }
        if (visited[node]) {
            return true;
        }
        visited[node] = true;
        for (int next : adjacency_list.at(node)) {
            if (hasCycle(adjacency_list, visited, next)) {
                return true;
            }
        }
        return visited[node] = false;
    }
};

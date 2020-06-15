#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool validate(const vector<vector<int>>& graph, const string& s) {
    for(int i = 0; i < s.length() - 1; i++) {
        if (graph[s[s.length() - 1] - 'a'][s[i] - 'a'] == 0) {
            return false;
        }
    }
    return true;
}

void backtracking(const string& s, const vector<vector<int>>& graph, vector<bool>& visited, string res) {
    if (res.length() == s.length()) {
        cout << res << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++) {
        if (!visited[i] and validate(graph, res + s[i])) {
            visited[i] = true;
            backtracking(s, graph, visited, res + s[i]);
            visited[i] = false;
        }
    }
}

int main() {
    string line;
    while(getline(cin, line)) {
        // Process line 1.
        string nodes;
        for (int i = 0; i < line.length(); i += 2) {
            nodes.push_back(line[i]);
        }
        sort(nodes.begin(), nodes.end());
        
        // Process line 2.
        getline(cin, line);
        vector<vector<int>> graph(26, vector<int>(26, 1));
        for (int i = 0; i < line.length(); i += 4) {
            graph[line[i] - 'a'][line[i + 2] - 'a'] = 0;
        }
        
        vector<bool> visited(26, false);
        backtracking(nodes, graph, visited, "");
        cout << endl;
    }

    return 0;
}

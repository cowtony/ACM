class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, int> parent;
        for (const vector<int>& edge : edges) {
            parent[edge.at(1)] = edge.at(0);
        }
        
        unordered_set<int> used_node;
        for (int node = 0; node < hasApple.size(); node++) {
            if (hasApple[node]) {
                int n = node;
                while (parent.find(n) != parent.end() and 
                       used_node.find(n) == used_node.end()) {
                    used_node.insert(n);
                    n = parent.at(n);
                }
            }
        }
        return used_node.size() * 2;
    }
};

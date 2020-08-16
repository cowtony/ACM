class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto graph = init(t);
        return helper(graph, s);
    }
    
private:
    // Time: O(len(t)^2), space O(26 len(t))
    vector<vector<int>> init(const string& t) {
        // Find 'abb' from 'ahbgdb':
        //        a  b  c  d  e  f  g  h  i  ...
        // -1  : (0) 2 -1  4 -1 -1  3  1 -1  ...
        // 0(a): -1 (2)-1  4 -1 -1  3  1 -1  ...
        // 1(h): -1  2 -1  4 -1 -1  3 -1 -1  ...
        // 2(b): -1 (5)-1  4 -1 -1  3 -1 -1  ...
        // 3(g): -1  5 -1  4 -1 -1 -1 -1 -1  ...
        // 4(d): -1  5 -1 -1 -1 -1 -1 -1 -1  ...
        // 5(b): -1 -1 -1 -1 -1 -1 -1 -1 -1  ... (The last row will always be -1)
        vector<vector<int>> graph(t.length() + 1, vector<int>(26, -1));
        for (int i = 0; i < t.length(); i++) {
            for (int j = i; j >= 0 and graph[j][t[i] - 'a'] == -1; j--) {
                graph[j][t[i] - 'a'] = i;
            }
        }
        return graph;
    }
    
    // Time: O(len(s)), space: O(1)
    bool helper(const vector<vector<int>>& graph, const string& s) {
        int j = 0;
        for (char c : s) {
            if (graph[j][c - 'a'] == -1) {
                return false;
            } else {
                j = graph[j][c - 'a'] + 1;
            }
        }
        return true;
    }
    
};

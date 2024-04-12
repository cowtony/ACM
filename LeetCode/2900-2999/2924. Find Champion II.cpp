class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (const auto& edge : edges) {
            indegree[edge[1]]++;
        }
        int node = -1;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                if (node == -1) {
                    node = i;
                } else {
                    return -1;
                }
            }
        }
        return node;
    }
};

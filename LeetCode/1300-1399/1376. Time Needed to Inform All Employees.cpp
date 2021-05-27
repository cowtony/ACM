class Solution {
public:
    int max_time = 0;
    map<int, set<int>> tree;
    vector<int> infoTime;
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Copy info time to global.
        infoTime = informTime;
        for (int i = 0; i < n; i++) {
            // Build the tree.
            if (tree.find(manager[i]) == tree.end()) {
                tree.emplace(manager[i], set<int>{i});
            } else {
                tree[manager[i]].insert(i);
            }
        }
        
        return dfs(headID);
    }
    
    int dfs(int head) {
        if (tree.find(head) == tree.end()) {
            return infoTime[head];
        }
        int max_time = 0;
        for (int sub : tree[head]) {
            max_time = max(max_time, dfs(sub));
        }
        return max_time + infoTime[head];
    }
};

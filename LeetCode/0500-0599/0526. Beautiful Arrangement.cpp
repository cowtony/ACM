class Solution {
public:
    int countArrangement(int N) {
        vector<bool> used(N + 1, false);
        return dfs(used, 1);
    }
    
    int dfs(vector<bool>& used, int depth) {
        if (depth == used.size()) {
            return 1;
        }
        int solution = 0;
        for (int i = 1; i < used.size(); i++) {
            if (!used[i] and (i % depth == 0 or depth % i == 0)) {
                used[i] = true;
                solution += dfs(used, depth + 1);
                used[i] = false;
            }
        }
        return solution;
    }
};
